echo "# s" >> README.md

git init

git add README.md

git commit -m "first commit"

git remote add origin https://github.com/iomeone/s.git

git push -u origin master


git submodule add https://github.com/WeAreROLI/JUCE.git thirdParty/JUCE

git submodule update --init --recursive

git commit -m "add submodule"



删除子模块较复杂，步骤如下：

rm -rf 子模块目录 删除子模块目录及源码
vi .gitmodules 删除项目目录下.gitmodules文件中子模块相关条目
vi .git/config 删除配置项中子模块相关条目
rm .git/module/* 删除模块下的子模块目录，每个子模块对应一个目录，注意只删除对应的子模块目录即可
执行完成后，再执行添加子模块命令即可，如果仍然报错，执行如下：

git rm --cached 子模块名称
