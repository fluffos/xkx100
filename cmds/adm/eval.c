// 测试专用
int main(object me, string arg)
{
    if (!wizardp(me))
        return 0;

    /* clean up first */
    if (file_size("/temp/tmp_eval_file.c") != -1)
    rm ("/temp/tmp_eval_file.c");
    if (find_object("/temp/tmp_eval_file"))
    destruct(find_object("/temp/tmp_eval_file"));

    write_file("/temp/tmp_eval_file.c","mixed eval() { " + arg + "; }\n");
    printf("Result = %O\n", "/temp/tmp_eval_file"->eval());
    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP
指令格式 : eval <lpc code>

测试专用，请先实现功能后运行。

HELP);

    return 1;
}
