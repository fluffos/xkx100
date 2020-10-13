// /d/shenlong/wanted_list.h
// Last Modified by winder on Jul. 12 2002

// filename : flag
// list the filenames of those special stuffs and their flags will determine
// how long the period is for chasers to take actions

mapping wanted_list = ([
	"/clone/weapon/treasure/baihong-jian.c"     : 1 ,//白虹剑
	"/clone/weapon/treasure/bishou.c"           : 1 ,//匕首
	"/clone/weapon/treasure/dragonblade.c"      : 1 ,//屠龙刀
	"/clone/weapon/treasure/duanyun-axe.c"      : 1 ,//断云斧
	"/clone/weapon/treasure/fumo-dao.c"         : 1 ,//伏魔刀
	"/clone/weapon/treasure/ganjiang-jian.c"    : 1 ,//干将
	"/clone/weapon/treasure/greenwater-sword.c" : 1 ,//碧水剑
	"/clone/weapon/treasure/green-sword.c"      : 1 ,//碧水剑
	"/clone/weapon/treasure/jiandao.c"          : 1 ,//五毒剪
	"/clone/weapon/treasure/jiaowei-qin.c"      : 1 ,//焦尾琴
	"/clone/weapon/treasure/jinfenggou.c"       : 1 ,//金凤钩
	"/clone/weapon/treasure/jinhua.c"           : 1 ,//夺命金花
	"/clone/weapon/treasure/jinlun.c"           : 1 ,//金轮
	"/clone/weapon/treasure/jinlongbian.c"      : 1 ,//金龙鞭
	"/clone/weapon/treasure/jinshe-jian.c"      : 1 ,//金蛇剑
	"/clone/weapon/treasure/jinwu-staff.c"      : 1 ,//金乌杖
	"/clone/weapon/treasure/king-blade.c"       : 1 ,//闯王宝刀
	"/clone/weapon/treasure/langyabang.c"       : 1 ,//狼牙棒
	"/clone/weapon/treasure/lingshezhang.c"     : 1 ,//灵蛇杖
	"/clone/weapon/treasure/liquan-qiang.c"     : 1 ,//沥泉枪
	"/clone/weapon/treasure/longquan-jian.c"    : 1 ,//龙泉剑
	"/clone/weapon/treasure/moye-jian.c"        : 1 ,//莫邪
	"/clone/weapon/treasure/qin.c"              : 1 ,//白玉瑶琴
	"/clone/weapon/treasure/qingguang-jian.c"   : 1 ,//青光剑
	"/clone/weapon/treasure/sea-wood.c"         : 1 ,//南海神木
	"/clone/weapon/treasure/skysword.c"         : 1 ,//倚天剑
	"/clone/weapon/treasure/xblade.c"           : 1 ,//血刀
	"/clone/weapon/treasure/xuantie-jian.c"     : 1 ,//玄铁重剑
	"/clone/weapon/treasure/xuantie-sword.c"    : 1 ,//玄铁剑
//	"/clone/weapon/treasure/yinlun.c"           : 1 ,//银轮
	"/clone/weapon/treasure/yitian-jian.c"      : 1 ,//倚天剑
	"/clone/weapon/treasure/ylbian.c"           : 1 ,//云龙鞭
	"/clone/weapon/treasure/youlong-jian.c"     : 1 ,//游龙剑
	"/clone/weapon/treasure/yuchang-jian.c"     : 1 ,//鱼肠剑
	"/clone/weapon/treasure/yuewang-jian.c"     : 1 ,//越王剑
	"/clone/weapon/treasure/zhanlu-jian.c"      : 1 ,//湛庐剑
	"/clone/weapon/treasure/zhen.c"             : 1 ,//绣花针
	"/clone/weapon/treasure/zhenwu-jian.c"      : 1 ,//真武剑
	"/clone/weapon/treasure/zhenyue.c"          : 1 ,//镇岳尚方
	"/clone/armor/treasure/baojia.c"            : 1 ,//真丝宝甲
	"/clone/armor/treasure/jingang-zhao.c"      : 1 ,//金刚罩
	"/clone/armor/treasure/wucanyi.c"           : 1 ,//乌蚕衣
	"/clone/armor/treasure/skirt.c"             : 1 ,//天蚕丝裙
	"/clone/book/9book.c"                       : 1 ,//九阴真本
//	"/clone/book/bagua0.c"                      : 1 ,//河图
//	"/clone/book/bagua1.c"                      : 1 ,//洛书
	"/clone/book/medicine6.c"                   : 1 ,//胡青牛医经
	"/clone/book/medicine7.c"                   : 1 ,//王难姑毒经
//	"/clone/book/jinshe1.c"                     : 1 ,//金蛇秘籍上册
//	"/clone/book/yijing0.c"                     : 1 ,//易经序卦篇
//	"/clone/book/yijing1.c"                     : 1 ,//易经说卦篇
//	"/clone/book/yijing2.c"                     : 1 ,//易经杂卦篇
//	"/clone/book/yijing3.c"                     : 1 ,//易经系辞篇
	"/clone/book/jiuyin1.c"                     : 1 ,//九阴真经上册
	"/clone/book/jiuyin2.c"                     : 1 ,//九阴真经下册
	"/clone/book/shipian.c"                     : 1 ,//长石片
/*	"/clone/weapon/xiangmo-chu.c"  : 1,  // 降魔杵
	"/clone/weapon/yitian-jian.c"  : 1,  // 倚天剑
	"/clone/unique/yuxiao.c"       : 1,  // 玉箫
	"/clone/unique/fumo-dao.c"     : 1,  // 伏魔刀
	"/clone/unique/jinshe-jian.c"  : 1,  // 金蛇剑
	"/clone/unique/eyujian.c"      : 1,  // 鳄嘴剪
	"/clone/unique/eweibian.c"     : 1,  // 鳄尾鞭
	"/clone/unique/xuantie-jian.c" : 1,  // 玄铁重剑
	"/d/huashan/obj/jinshe-zhui.c" : 1,  // 金蛇锥
	"/clone/unique/yuzhu-zhang.c"  : 1,  // 玉竹杖
	"/clone/weapon/qijue.c"        : 1,  // 七绝针
	"/clone/unique/yuchang-jian.c" : 1,  // 鱼肠剑
	"/clone/unique/zhenwu.c"       : 1,  // 真武剑
	"/clone/unique/cy-jian.c"      : 1,  // 重阳剑
	"/d/shaolin/obj/jingang-zhao.c": 1,  // 金刚罩
	"/d/xueshan/obj/wucan-yi.c"    : 1,  // 乌蚕衣
	"/d/taohua/obj/ruanwei-jia.c"  : 1,  // 软猬甲
	"/d/taohua/obj/taomu-jian.c"   : 1,  // 桃木剑
	"/clone/unique/xuedao.c"       : 1,  // 血刀
	"/d/city/npc/obj/shenzhao.c"   : 3,  // 神照经
	"/kungfu/class/wudang/obj/canpian.c" : 3, //九阳残篇
	"/clone/unique/jiuyin_force_book.c" : 3, //九阴真经
	"/clone/unique/kusang-bang.c"	: 1,	// 哭丧棒
	"/clone/drug/renshen_guo.c"    : 1,
	"/clone/drug/xuelian.c"               : 1,
	"/clone/drug/xueteng.c"               : 1,
	"/clone/drug/shouwu.c"               : 1,
	"/clone/drug/puti-zi.c"               : 1,
	"/clone/drug/sheli-zi.c"      : 1,
	"/clone/drug/cb_renshen.c"     : 1,
	"/clone/drug/danggui.c"               : 1,*/
]);
