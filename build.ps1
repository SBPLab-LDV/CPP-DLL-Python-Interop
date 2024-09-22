# 創建構建目錄
New-Item -ItemType Directory -Force -Path "build"
Set-Location "build"

# 運行 CMake 配置
cmake ..

# 構建項目
cmake --build . --config Release

# 复制 DLL 到项目根目录
Copy-Item "Release\example.dll" ".." -Force

# 返回到项目根目录
Set-Location ..

Write-Host "Build completed. The DLL has been copied to the project root directory."

# 指定 Anaconda Python 路徑
$pythonPath = "D:\anaconda3\python.exe"

# 運行 Python 腳本
& $pythonPath use_example.py

Write-Host "Build and run completed."