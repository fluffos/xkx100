// zhi.h 蹇楀瓧杈堟敹寰掑拰鎺ㄨ崘缁欏�瀛楄緢

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("quanzhen xin2", ob) )
	{
		command("say 鎬庨航鏍凤紝浣犳嬁鎴戠殑鎺ㄨ崘淇″幓鎷滃笀浜嗗悧 ?");
		return 0;
	}

	if((obj->query("id") == "quanzhen ling")
	&& ob_fam["family_name"] == "鍏ㄧ湡鏁�"
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") )
	{
		ob->set_temp("fight_ok",1);
	        command("say 濂斤紝鏃㈢劧宸叉湁鎺岄棬鐪熶汉璁稿彲锛屾垜浠�氨鏉ラ獙璇佷竴涓嬫�鍔熴€�");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

	if (obj->query("id")=="quanzhen xin1" && ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 濂斤紝"+ob->query("name")+"锛屼綘鎰挎剰鎷滄垜涓哄笀鍚楋紵");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

        command("smile");
        command("say 杩欎笢瑗跨粰鎴戝彲娌℃湁浠€楹界敤銆�");
        command("give " + obj->query("id") + " to " + me->query("id"));
	return 0;
}

void destroying(object me, object obj)
{
	destruct(obj);
	return;
}

int accept_fight(object ob)
{
	object me  = this_object();

	if ( !ob->query_temp("fight_ok") ) return 0;

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	ob->delete_temp("fight_ok");

	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_qi, his_max_qi;

	my_max_qi  = me->query("max_qi");
	his_max_qi = ob->query("max_qi");

	if (me->is_fighting())
	{
		call_out("checking",2, me, ob);
                return 1;
	}

	if ( !present(ob, environment()) ) return 1;

	if (( (int)me->query("qi")*100 / my_max_qi) <= 50 )
	{
		command("say 闈掑嚭鏂艰摑鑳滄柤钃濓紝涓嶆劎鏄�叏鐪熼棬涓嬪紵瀛愶紒鎭�枩浣犱簡锛乗n");
		message_vision("$N浜ょ粰$n涓€灏佹帹鑽愪俊銆俓n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/quanzhen/obj/tuijianxin-2");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
	{
		command("say 鐪嬫潵" + RANK_D->query_respect(ob) +
			"杩樺緱澶氬姞缁冧範锛屾柟鑳藉湪鏈�暀璇稿�寮熷瓙涓�嚭浜哄ご鍦帮紒\n");
		return 1;
	}

	return 1;
}

void attempt_apprentice(object ob)
{
	object me = this_object();
	mapping ob_fam;
	mapping my_fam = me->query("family");
	string name, new_name;
	name = ob->query("name");

	if ((int)ob->query_skill("xiantian-qigong",1) < 30 ) {
		command("say 浣犵殑鏈�棬鍐呭姛蹇冩硶鐏�€欎笉瓒�,闅句互棰嗙暐鏇撮珮娣辩殑姝﹀姛銆�");
		return;
	}
	if ((int)ob->query("shen") < 1000) {
		command( "say 琛屼緺浠椾箟鏄�垜杈堝�姝︿汉鐨勫熀鏈�搧璐�紝浣犺嫢鑳藉�鍋氫簺渚犱箟涔嬩簨锛屾垜涓€瀹氭敹浣犱负寰掋€俓n");
		return;
	}
        if (ob->query("gender")=="鐢锋€�" && me->query("gender")=="濂虫€�") {
                command("say 鎴戜笉鏀剁敺寰掞紝浣犺繕鏄�幓鎷滄垜鍑犱綅甯堝厔涓哄笀鍚с€俓n");
                return;
        }
	if(!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "鍏ㄧ湡鏁�")
	{
		command("say 鎴戞暀涓虹巹闂ㄦ�瀹楋紝" + RANK_D->query_respect(ob) + "鑻ヨ�瀛﹁壓锛岃繕鏄�厛鎵炬湰闂ㄥ洓浠ｅ紵瀛愬惂銆�");
		return;
	}
	if ( ob_fam["generation"] == 0 )
	{
		command("say 鏃犻噺瀵夸經锛佷綘杩樻槸鍏堟壘鍥涗唬寮熷瓙瀛︾偣鍩烘湰鍔熷惂銆�");
		return;
	}
	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say "+RANK_D->query_respect(ob)+"锛岃传閬撳摢閲屾暍褰擄紒");
		return;
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 1))
	{
		command("say 鎴戝拰"+ob_fam["master_name"]+"鎶㈠緬寮燂紝鍝堝搱鍝堬紒");
		command("recruit " + ob->query("id"));
	}
	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");

			command("say 鏄�"+ob_fam["master_name"]+"鍙�綘鏉ユ壘鎴戠殑锛熷ソ锛屽ソ銆�");
			command("say 璐�亾鐪嬩綘鏄�彲濉戜箣鎵嶏紝浣犲氨瀹夊績瀛﹁壓鍚э紒");
			if(ob->query("class") == "quanzhen")
			{
				new_name = name[0..1] + "娓�" + name[4..5];
				ob->set("name", new_name);
				command("say 浠庝粖浠ュ悗浣犵殑閬撳彿鍙�仛"+new_name+ "锛屼綘鐜板湪鏄�叏鐪熸暀娓呭瓧杈堝紵瀛愪簡銆�");
			}
			else command("say 浣犳病鏈夊嚭瀹讹紝鎴戣櫧鍙�互鏀朵綘锛屼互鍚庝綘鍙�埆鍚庢倲浜嗐€�");
			command("recruit " + ob->query("id"));
		}
		else
		{
			command("say " + RANK_D->query_respect(ob) + "锛屼綘娌℃湁鎺ㄨ崘淇★紝涓嶈兘瓒婄骇鎷滃笀銆�");
			return;
		}
	}
	return;
}
