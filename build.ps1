# 創建構建目錄
$buildDir = "build"
if (!(Test-Path -Path $buildDir)) {
    New-Item -ItemType Directory -Force -Path $buildDir
}

# 進入構建目錄
Set-Location $buildDir

# 運行 CMake
cmake ..

# 構建項目
cmake --build . --config Release

# 返回到原目錄
Set-Location ..

# 複製 DLL 到當前目錄（如果需要）
Copy-Item "$buildDir/bin/Release/example.dll" .

# 指定 Anaconda Python 路徑
$pythonPath = "D:\anaconda3\python.exe"

# 運行 Python 腳本
& $pythonPath use_example.py

Write-Host "Build and run completed."