/*********
src/ds_tree.c
*********/
static int ds_tree_flag=0;

void ds_tree_init(void){
	if(ds_tree_flag){
		//module inited.
		return;
	}
	
	ds_tree_flag =1;
	//todo:module init...
	
}

void ds_tree_destroy(void){
	if (!ds_tree_flag) {
        //log("module not inited..",X);
	        return;
   	}
   	ds_tree_flag = 0;
    //todo:module destory...

}

