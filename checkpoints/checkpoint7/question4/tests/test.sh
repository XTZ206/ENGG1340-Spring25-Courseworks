cp ../binary/reverse .
echo "Testing"
./reverse < input.txt > output.txt
diff output.txt expected.txt
