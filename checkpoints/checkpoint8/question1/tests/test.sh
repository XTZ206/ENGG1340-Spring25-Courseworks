cp ../binary/mode .

echo "Testing"
./mode < input.txt > output.txt
diff output.txt expected.txt