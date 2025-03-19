cp ../binary/election .

echo "Testing"
./election < input.txt > output.txt
diff output.txt expected.txt