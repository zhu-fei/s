echo "# s" >> README.md

git init

git add README.md

git commit -m "first commit"

git remote add origin https://github.com/iomeone/s.git

git push -u origin master


git submodule add https://github.com/WeAreROLI/JUCE.git thirdParty

git submodule update --init --recursive

git commit -m "add submodule"