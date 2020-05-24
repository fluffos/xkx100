// nick.c
inherit F_CLEAN_UP;

#include <ansi.h>



int main(object me, string arg)
{
	if( !arg ) return notify_fail("你要替自己取什么绰号？\n");
	if( arg == "none" ) 
	{
		me->delete("nickname");
		write("你的绰号取消了。\n");
		return 1;
	}
	if( !wizardp(me) && strlen(arg) > 30 )
		return notify_fail("你的绰号太长了，想一个短一点的、响亮一点的。\n");

	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);

	me->set("nickname", arg + NOR);
	write("你取好了绰号。\n");
	return 1;
}
int help(object me)
{
	write(@HELP
指令格式 : nick <外号, 绰号> | none
 
    这个指令可以让你为自己取一个响亮的名号或头衔，nick none
取消绰号。你如果希望在绰号中使用ansi的控制字元改变颜色，可以
用以下的控制字串：（其中系统自动会在字串尾端加一个 $NOR$）

        $ＢＬＫ$：[30m黑色[0m          
        $ＲＥＤ$：[31m红色[0m          $ＨＩＲ$：[1;31m亮红色[0m
        $ＧＲＮ$：[32m绿色[0m          $ＨＩＧ$：[1;32m亮绿色[0m
        $ＹＥＬ$：[33m土黄色[0m        $ＨＩＹ$：[1;33m黄色[0m
        $ＢＬＵ$：[34m深蓝色[0m        $ＨＩＢ$：[1;34m蓝色[0m
        $ＭＡＧ$：[35m浅紫色[0m        $ＨＩＭ$：[1;35m粉红色[0m
        $ＣＹＮ$：[36m蓝绿色[0m        $ＨＩＣ$：[1;36m天青色[0m
        $ＷＨＴ$：[37m浅灰色[0m        $ＨＩＷ$：[1;37m白色[0m
        $ＮＯＲ$：[0m恢复正常颜色[0m

HELP
	);
	return 1;
}
