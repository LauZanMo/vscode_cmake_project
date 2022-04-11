# vscode_CMake_project

> author：刘正武
>
> 用于vscode开发CMake工程的模板

## 依赖插件

- ms-vscode.cpptools-extension-pack插件

## 使用

直接在此工程上开发CMake即可，除此之外：

- 修改C/C++扩展设置的Clang_format_style为file可以通过ctrl+shift+i来格式化C++代码

- 修改 [settings.json](.vscode/settings.json) 中的

  - doxdocgen.file.copyrightTag
  - doxdocgen.generic.authorEmail
  - doxdocgen.generic.authorName

  以实现自定义的注释生成(在代码中输入 ‘/**’ + 回车 可触发)