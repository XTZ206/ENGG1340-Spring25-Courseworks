cp ../binary/courses .

echo "Test 1"
./courses < input1.txt > output1.txt
diff output1.txt expected1.txt

echo "Test 2"
./courses < input2.txt > output2.txt
diff output2.txt expected2.txt
