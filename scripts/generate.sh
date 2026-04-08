#!/bin/bash
set -euo pipefail

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
PROJECT_ROOT="$SCRIPT_DIR/.."

S2_WS_JSON_DIR="$PROJECT_ROOT/ext/s2-ws-json"
BUILD_DIR="$PROJECT_ROOT/tmp"

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"

# Making a copy of the JSON schemas.
cp -r "$S2_WS_JSON_DIR/s2-json-schema/"* "$BUILD_DIR"

# Renaming the schemas to remove ".schema" to avoid schema suffix from ending up in code generated files.
find "$BUILD_DIR" -type f -name "*.schema.json" -exec bash -c '
  for f; do
    mv -- "$f" "${f/.schema.json/.json}"
  done
' bash {} +

# Update the references
if sed --version >/dev/null 2>&1; then
  # GNU sed
  find "$BUILD_DIR" -type f -name "*.json" -exec sed -i 's/\.schema\.json/.json/g' {} +
else
  # BSD sed (macOS)
  find "$BUILD_DIR" -type f -name "*.json" -exec sed -i '' 's/\.schema\.json/.json/g' {} +
fi

# Fix conflict with system timer struct
mv "$BUILD_DIR/schemas/Timer.json" "$BUILD_DIR/schemas/TimerType.json"
# Update the references
if sed --version >/dev/null 2>&1; then
  # GNU sed
  find "$BUILD_DIR" -type f -name "*.json" -exec sed -i 's/Timer\.json/TimerType.json/g' {} +
else
  # BSD sed (macOS)
  find "$BUILD_DIR" -type f -name "*.json" -exec sed -i '' 's/Timer\.json/TimerType.json/g' {} +
fi

# Generate openapi file

OUTPUT="$BUILD_DIR/openapi.yaml"
SCHEMA_DIR="$BUILD_DIR/messages"

echo "openapi: 3.0.3" > "$OUTPUT"
echo "info:" >> "$OUTPUT"
echo "  title: s2" >> "$OUTPUT"
echo "  version: 1.0.0" >> "$OUTPUT"

echo "paths:" >> "$OUTPUT"
echo "  /_models:" >> "$OUTPUT"
echo "    get:" >> "$OUTPUT"
echo "      responses:" >> "$OUTPUT"
echo "        '200':" >> "$OUTPUT"
echo "          description: All models" >> "$OUTPUT"
echo "          content:" >> "$OUTPUT"
echo "            application/json:" >> "$OUTPUT"
echo "              schema:" >> "$OUTPUT"
echo "                \$ref: '#/components/schemas/AllModels'" >> "$OUTPUT"

echo "components:" >> "$OUTPUT"
echo "  schemas:" >> "$OUTPUT"

# --- Generate schema refs ---
for f in "$SCHEMA_DIR"/*.json; do
  name=$(basename "$f" .json)
  safe_name=$(echo "$name" | sed 's/[^a-zA-Z0-9]/_/g')

  echo "    $safe_name:" >> "$OUTPUT"
  echo "      \$ref: './messages/$name.json'" >> "$OUTPUT"
done

# --- Generate AllModels ---
echo "    AllModels:" >> "$OUTPUT"
echo "      type: object" >> "$OUTPUT"
echo "      properties:" >> "$OUTPUT"

for f in "$SCHEMA_DIR"/*.json; do
  name=$(basename "$f" .json)
  safe_name=$(echo "$name" | sed 's/[^a-zA-Z0-9]/_/g')

  prop_name=$(echo "$safe_name" | sed -E 's/^([A-Z]+)/\L\1/')

  echo "        $prop_name:" >> "$OUTPUT"
  echo "          \$ref: '#/components/schemas/$safe_name'" >> "$OUTPUT"
done

echo "✅ Generated $OUTPUT"

# Generate C code
npx openapi-generator-cli generate -i "$BUILD_DIR/openapi.yaml" -g c -o "$BUILD_DIR/generated" -t "$PROJECT_ROOT/templates"

# Copy to the intermediate folder
mkdir -p "$BUILD_DIR/intermediate"
cp -r "$BUILD_DIR/generated/include/"* "$BUILD_DIR/intermediate/"
cp -r "$BUILD_DIR/generated/model/"* "$BUILD_DIR/intermediate/"
cp -r "$BUILD_DIR/generated/src/"* "$BUILD_DIR/intermediate/"
rm "$BUILD_DIR/intermediate/all_models."*
rm "$BUILD_DIR/intermediate/any_type."*
rm "$BUILD_DIR/intermediate/apiClient."*
mv "$BUILD_DIR/intermediate/apiKey.c" "$BUILD_DIR/intermediate/keyValuePair.c"

# Replace "#include "../external/cJSON.h" with "#include <cjson/cJSON.h>"
if sed --version >/dev/null 2>&1; then
  # GNU sed
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i 's/#include "..\/external\/cJSON.h"/#include <cjson\/cJSON.h>/g' {} +
else
  # BSD sed (macOS)
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i '' 's/#include "..\/external\/cJSON.h"/#include <cjson\/cJSON.h>/g' {} +
fi

# Replace "#include "../include/list.h" with "#include "list.h""
if sed --version >/dev/null 2>&1; then
  # GNU sed
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i 's/#include "..\/include\/list.h"/#include <s2schema\/list.h>/g' {} +
else
  # BSD sed (macOS)
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i '' 's/#include "..\/include\/list.h"/#include <s2schema\/list.h>/g' {} +
fi

# Replace "#include "../include/keyValuePair.h"" with "#include "keyValuePair.h""
if sed --version >/dev/null 2>&1; then
  # GNU sed
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i 's/#include "..\/include\/keyValuePair.h"/#include <s2schema\/keyValuePair.h>/g' {} +
else
  # BSD sed (macOS)
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i '' 's/#include "..\/include\/keyValuePair.h"/#include <s2schema\/keyValuePair.h>/g' {} +
fi

#Replace "#include "../include/binary.h"" with "#include "binary.h""
if sed --version >/dev/null 2>&1; then
  # GNU sed
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i 's/#include "..\/include\/binary.h"/#include <s2schema\/binary.h>/g' {} +
else
  # BSD sed (macOS)
  find "$BUILD_DIR/intermediate" -type f \( -name "*.c" -o -name "*.h" \) -exec sed -i '' 's/#include "..\/include\/binary.h"/#include <s2schema\/binary.h>/g' {} +
fi

mkdir -p "$PROJECT_ROOT/include/s2schema"
cp "$BUILD_DIR/intermediate/"*.h "$PROJECT_ROOT/include/s2schema/"

mkdir -p "$PROJECT_ROOT/src"
cp "$BUILD_DIR/intermediate/"*.c "$PROJECT_ROOT/src/"