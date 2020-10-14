// 测试专用
int main(object me, string arg)
{
    /* clean up first */

    return 1;
}

int help(object me)
{
    if (!wizardp(me))
        return 0;

    write(@HELP

测试专用，请先实现功能后运行。

HELP);

    return 1;
}
