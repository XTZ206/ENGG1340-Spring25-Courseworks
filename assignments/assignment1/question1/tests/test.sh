cp ../sources/1.sh .
echo "Test 1"
./1.sh tale ebook.txt > outputs/output1_1.txt
diff outputs/output1_1.txt expected/output1_1.txt

echo "Test 2"
./1.sh time ebook.txt > outputs/output1_2.txt
diff outputs/output1_2.txt expected/output1_2.txt

echo "Test 3"
./1.sh jerry ebook.txt > outputs/output1_3.txt
diff outputs/output1_3.txt expected/output1_3.txt

echo "Test 4"
./1.sh pokemon ebook.txt > outputs/output1_4.txt
diff outputs/output1_4.txt expected/output1_4.txt