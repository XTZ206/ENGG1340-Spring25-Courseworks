cd ..
g++ -std=c++11 --pedantic-errors sources/semiprime.cpp -o binary/semiprime
cp binary/semiprime tests/
cd tests

echo "Test 1"
./semiprime < inputs/input1_1.txt > outputs/output1_1.txt
diff outputs/output1_1.txt expected/output1_1.txt

echo "Test 2"
./semiprime < inputs/input1_2.txt > outputs/output1_2.txt
diff outputs/output1_2.txt expected/output1_2.txt

echo "Test 3"
./semiprime < inputs/input1_3.txt > outputs/output1_3.txt
diff outputs/output1_3.txt expected/output1_3.txt