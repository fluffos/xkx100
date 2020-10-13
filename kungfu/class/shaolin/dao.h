// dao.h for fight and get letter from Dao

int accept_object(object ob, object obj)
{
	object me = this_object();

	mapping my_fam  = me->query("family");
	mapping ob_fam  = ob->query("family");

	if ( ob->query_temp("have_letter") && present("tuijian xin2", ob) )
	{
		command("say 鎬庨航鏍凤紝浣犳嬁鎴戠殑鎺ㄨ崘淇″幓鎷滃笀浜嗗悧 ?");
		return 0;
	}

	if((obj->query("id") == "damo ling")
	&& ob_fam["generation"] == my_fam["generation"] + 1
	&& !ob->query_temp("have_letter") )
	{
		ob->set_temp("fight_ok",1);
	        command("say 濂斤紝鏃㈢劧宸插緱鍒版柟涓堣�鍙�紝鎴戜滑灏辨潵楠岃瘉涓€涓嬫�鍔熴€�");
		remove_call_out("destroying");
		call_out("destroying", 1, me, obj);
		return 1;
	}

	if (obj->query("id") == "tuijian xin1"
	&& ob->query_temp("have_letter") )
	{
		ob->set_temp("apprentice_ok",1);
	        command("say 濂斤紝" + ob->query("name") + "锛屼綘鎰挎剰鎷滄垜涓哄笀鍚楋紵");
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
		command("say 闈掑嚭鏂艰摑鑳滄柤钃濓紝涓嶆劎鏄�皯鏋楀�鐨勪匠寮熷瓙 ! 鎭�枩浣犱簡 !\n");
		message_vision("$N浜ょ粰$n涓€灏佹帹鑽愪俊銆俓n", me, ob);
		ob->set_temp("have_letter",1);
		obj=new("/d/shaolin/obj/tuijianxin-2");
		obj->move(ob);
		return 1;
	}

	if (( (int)ob->query("qi")*100 / his_max_qi) < 50 )
	{
		command("say 鐪嬫潵" + RANK_D->query_respect(ob) +
			"杩樺緱澶氬姞缁冧範锛屾柟鑳藉湪灏戞灄璇稿�寮熷瓙涓�嚭浜哄ご鍦� !\n");
		return 1;
	}

	return 1;
}

void attempt_apprentice(object ob)
{
	object me  = this_object();
	mapping ob_fam;
	mapping my_fam  = me->query("family");

	string name, new_name;

	name = ob->query("name");

	if (!(ob_fam = ob->query("family")) || ob_fam["family_name"] != "灏戞灄娲�")
	{
		command("say " + RANK_D->query_respect(ob) + "涓庢湰娲剧礌鏃犳潵寰€锛屼笉鐭ユ�璇濅粠浣曡皥璧凤紵");
		return;
	}

	if ( (string)ob->query("class")!="bonze" && ob_fam["family_name"] == "灏戞灄娲�")
	{
		command("say " + RANK_D->query_respect(ob) + "鏄�織瀹跺紵瀛愶紝涓嶈兘鍦ㄥ�鍐呭�鑹恒€�");
		return;
	}

	if ( ob_fam["generation"] == 0 )
	{
		command("say 闃垮讥闄€浣涳紒璐�儳灏辨敹涓嬩綘鍋氭垜鐨勫紵瀛愪簡銆�");
		command("recruit " + ob->query("id"));
		return;
	}

	if ( ob_fam["generation"] <= my_fam["generation"] )
	{
		command("say " + RANK_D->query_respect(ob) + "锛岃传鍍у摢閲屾暍褰� !");
		return;
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 1) && name[0..1] == "娓�")
	{
		command("say " + ob_fam["master_name"] + "鐨勫緬寮熸€庨航璺戝埌鎴戣繖鍎挎潵浜嗭紝鍝堝搱鍝� !");
		command("recruit " + ob->query("id"));
	}

	if ( ob_fam["generation"] == (my_fam["generation"] + 2) )
	{
		if ( ob->query_temp("apprentice_ok") )
		{
			ob->delete_temp("have_letter");
			ob->delete_temp("apprentice_ok");

			command("say 鏄�" + ob_fam["master_name"] + "鍙�綘鏉ユ壘鎴戠殑鍚э紝鍝堝搱鍝� !");
			command("say 璐�儳鍙堝緱涓€鍙��涔嬫墠锛岀湡鏄�彲鍠滃彲璐� !");

			new_name = "娓�" + name[2..3];
			ob->set("name", new_name);

			command("say 浠庝粖浠ュ悗浣犵殑娉曞悕鍙�仛" + new_name + "锛屾伃鍠滀綘鑽ｅ崌涓哄皯鏋楁淳娓呭瓧杈堝紵瀛� !");
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
