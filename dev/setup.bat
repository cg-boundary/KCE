@echo off

echo Installing...

for /f "delims=" %%A in ('python -c "import site; print(site.getsitepackages()[0])"') do (
    copy ..\build\Debug\KCE.cp313-win_amd64.pyd "%%A\KCE.pyd" /Y
)

echo Done! Installed to Python site-packages.
