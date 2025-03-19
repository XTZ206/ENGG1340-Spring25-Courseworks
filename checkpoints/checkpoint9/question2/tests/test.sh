cp ../binary/shopvec .

echo "Testing"
./shopvec > output.txt
diff output.txt expected.txt
