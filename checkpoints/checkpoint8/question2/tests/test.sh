cp ../binary/railway .

echo "Testing"
./railway < input.txt > output.txt
diff output.txt expected.txt