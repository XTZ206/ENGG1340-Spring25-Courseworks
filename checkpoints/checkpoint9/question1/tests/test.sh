cp ../binary/stulist .

echo "Test 1"
./stulist < inputs/input1.txt > outputs/output1.txt
diff outputs/output1.txt expected/expected1.txt

echo "Test 2"
./stulist < inputs/input2.txt > outputs/output2.txt
diff outputs/output2.txt expected/expected2.txt

echo "Test 3"
./stulist < inputs/input3.txt > outputs/output3.txt
diff outputs/output3.txt expected/expected3.txt
