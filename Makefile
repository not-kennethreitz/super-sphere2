run: love
	love dist/supersphere2.love

love:
	rm -fr supersphere2.love
	zip -r dist/supersphere2.love assets vendor *.lua

ios:
	mv conf.lua conf.default.lua
	mv conf.mobile.lua conf.lua
	$(MAKE) love

	mv conf.lua conf.mobile.lua
	mv conf.default.lua conf.lua

mac: love
	mv dist/supersphere2.love dist/macos/Super\ Sphere\ II.app/Contents/Resources/supersphere2.love
	cd dist/macos && zip -r supersphere2-app-OSX.zip *
	mv dist/macos/supersphere2-app-OSX.zip dist/
	rm -fr dist/macos/Super\ Sphere\ II.app/Contents/Resources/supersphere.love

windows: love

	cd dist/windows && cat .love.exe ../supersphere2.love > SuperSphereII.exe
	# winresourcer --operation=Update --exeFile=dist/windows/SuperSphere.exe --resourceType=Icongroup --resourceName:1 --resourceFile:dist/windows/game.ico
	# winresourcer --operation=Update --exeFile=dist/windows/SuperSphere.exe --resourceType=Icon --resourceName:4 --resourceFile:dist/windows/game.ico
	# winresourcer --operation=Update --exeFile=dist/windows/SuperSphere.exe --resourceType=Icon --resourceName:5 --resourceFile:dist/windows/game.ico
	cd dist/windows && zip -r supersphere2-WIN.zip *
	mv dist/windows/supersphere2-WIN.zip dist/
	rm -fr dist/supersphere2.love
	rm -fr dist/windows/SuperSphereII.exe

android:
	mv conf.lua conf.default.lua
	mv conf.mobile.lua conf.lua
	$(MAKE) love

	mv conf.lua conf.mobile.lua
	mv conf.default.lua conf.lua

	cp dist/supersphere2.love dist/android/app/src/main/assets/game.love
	cd dist/android && ./gradlew build
	mv dist/android/app/build/outputs/apk/app-debug.apk dist/supersphere-ANDROID.apk
	rm -fr dist/android/app/src/main/assets/game.love
