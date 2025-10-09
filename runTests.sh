#!/bin/bash
cd "$WORKSPACE"
./build/test/rectangle-test --gtest_output=xml:test/test_results.xml || true


