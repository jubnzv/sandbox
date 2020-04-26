#!/usr/bin/env bash
python3 -m jschema_to_python   \
    --schema-path schema.json  \
    --module-name test          \
    --output-directory test_om  \
    --root-class-name TestRoot \
    --force \
    -vv
