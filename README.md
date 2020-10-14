# xkx100
侠客行100 UTF-8 中文版

Updated the files to work with FluffOS following the guidelines in the following,
https://forum.fluffos.info/t/common-lpc-migration-issues-v2019/1341

## 使用说明

请使用 fluffos v2019 最新版驱动

    driver config.ini

游戏端口：5555、6666(GBK编码)；网页访问端口：8888

本LIB为GBK旧版升级到utf-8版，目前代码基本无编译错误，原代码BUG已基本修复，升级造成的BUG已知部分已修复，不过中文字符判断（中文判断`[0..1]`需要改为`[0..0]`）可能存在遗漏，目前已知存在以下问题：

1. 中文字符排版显示未完全修复，比如地图，会影响排版美观；
2. 表情系统无效，因为emoted.o文件中空，可自己使用 edemote 指令补充；
3. 技能中文翻译不全，因为e2c_dict.o是从[炎黄LIB](https://github.com/oiuv/mud)中复制过来的，对游戏中显示为英文的地方需要自己补充翻译（补充方式如：chinese city=扬州）
