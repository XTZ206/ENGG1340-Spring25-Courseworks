cp ../sources/2.sh .
chmod +x 2.sh

echo "Test 1"
./2.sh < inputs/input2_1.txt > outputs/output2_1.txt
diff outputs/output2_1.txt expected/output2_1.txt

echo "Test 2"
./2.sh < inputs/input2_2.txt > outputs/output2_2.txt
diff outputs/output2_2.txt expected/output2_2.txt

echo "Test 3"
./2.sh < inputs/input2_3.txt > outputs/output2_3.txt
diff outputs/output2_3.txt expected/output2_3.txt

echo "Test 4"
./2.sh < inputs/input2_4.txt > outputs/output2_4.txt
diff outputs/output2_4.txt expected/output2_4.txt