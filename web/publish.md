Web 代码发布流程
---------------

1. 新建 /exfe/exfelight 目录
  mkdir /exfe/exfelight
  cd /exfe/exfelight
  git init && touch Readme.md && git add . && git commit -m 'Hello exfelight!'
  git config --add receive.denycurrentbranch ignore
  sudo su git && git checkout -f
