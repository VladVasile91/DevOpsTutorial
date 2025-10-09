#!/bin/bash
cd test
./rectangle-test --gtest_output=xml:test_results.xml || true
