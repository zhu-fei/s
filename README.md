echo "# s" >> README.md

git init

git add README.md

git commit -m "first commit"

git remote add origin https://github.com/iomeone/s.git

git push -u origin master


git submodule add https://github.com/WeAreROLI/JUCE.git thirdParty/JUCE

git submodule update --init --recursive

git commit -m "add submodule"



ɾ����ģ��ϸ��ӣ��������£�

rm -rf ��ģ��Ŀ¼ ɾ����ģ��Ŀ¼��Դ��
vi .gitmodules ɾ����ĿĿ¼��.gitmodules�ļ�����ģ�������Ŀ
vi .git/config ɾ������������ģ�������Ŀ
rm .git/module/* ɾ��ģ���µ���ģ��Ŀ¼��ÿ����ģ���Ӧһ��Ŀ¼��ע��ֻɾ����Ӧ����ģ��Ŀ¼����
ִ����ɺ���ִ�������ģ������ɣ������Ȼ����ִ�����£�

git rm --cached ��ģ������
