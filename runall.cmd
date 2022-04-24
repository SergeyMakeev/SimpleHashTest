.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=CtorDtor* --output=csv/test01.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=ClearAndInsertSeq* --output=csv/test02.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=InsertRndClearAndReInsert* --output=csv/test03.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=InsertRndAndRemove* --output=csv/test04.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=CtorSingleEmplaceDtor* --output=csv/test05.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=InsertAccessWithProbability10* --output=csv/test06.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=InsertAccessWithProbability50* --output=csv/test07.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=SearchNonExisting* --output=csv/test08.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=SearchExisting* --output=csv/test09.csv
.\build2019\Release\SimpleHashTest.exe --confidence=50 --filter=ClearAndInsertRnd* --output=csv/test10.csv
cd csv
python combine.py > combined.csv
cd ..
