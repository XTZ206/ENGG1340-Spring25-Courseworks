cd ..
g++ -std=c++11 --pedantic-errors sources/main.cpp sources/turtle.cpp sources/utils.cpp -o binary/turtle
cp binary/turtle tests/
cd tests

echo "Test 1"
./turtle < inputs/input2_1.txt > outputs/output2_1.txt
diff outputs/output2_1.txt expected/output2_1.txt

echo "Test 2"
./turtle < inputs/input2_2.txt > outputs/output2_2.txt
diff outputs/output2_2.txt expected/output2_2.txt

echo "Test 3"
./turtle < inputs/input2_3.txt > outputs/output2_3.txt
diff outputs/output2_3.txt expected/output2_3.txt