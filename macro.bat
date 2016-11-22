//애니메이션 프로그램 복사
xcopy /y .\OpenCV\Practice\bin\*.* .\Final
xcopy /y .\OpenCV\Practice\Include\Background\*.* .\Final\Background\

//캐릭터 추출 프로그램 복사
xcopy /y .\CharacterProcessing\CharacterProcessing\Character\*.* .\Final\Character\
xcopy /y .\CharacterProcessing\CharacterProcessing\CharacterImage\*.* .\Final\CharacterImage\
xcopy /y .\CharacterProcessing\CharacterProcessing\height\*.* .\Final\height\
xcopy /y .\CharacterProcessing\CharacterProcessing\image\*.* .\Final\image\
xcopy /y .\CharacterProcessing\CharacterProcessing\export\*.* .\Final\export\

xcopy /y .\CharacterProcessing\CharacterProcessing\haarcascade_eye_tree_eyeglasses.xml .\Final\
xcopy /y .\CharacterProcessing\CharacterProcessing\haarcascade_frontalface_default.xml .\Final\

xcopy /y .\CharacterProcessing\x64\Debug\*.* .\Final\