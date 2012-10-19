 	#!/bin/bash
 	MODULE_NAME=$1
 	 
 	SRC_DIR_NAME=src
 	INC_DIR_NAME=inc
 	BIN_DIR_NAME=bin
 	OBJ_DIR_NAME=obj
 	C_FILE_SUFFIX=.c
 	H_FILE_SUFFIX=.h
 	TEST_FILE_SUFFIX=.t
 	CREATE_FILE_FLAG=-f
 	CREATE_TEST_FILE_FLAG=-t
 	OVERWRITE_FILE=0
 	NOT_OVERWRITE_FILE=1
 	 
 	create_mkdir(){
 	mkdir $1 > /dev/null 2>&1
 	if [ $? = 0 ];then  
 	echo /$1 had created
 	else
 	echo /$1 had exist
 	fi
 	 
 	}
 	check_file_exist(){
 	    if [ -e $1 ];then
 	        while :;do
 	            echo -n "the $1 had exist , do you want to overwrite?(y(Y) done:n(N) not:e(E) exit) : "
 	            read check_file_exist_ans
 	            case $check_file_exist_ans in
 	            y|Y)
 	                echo you answer y
 	                return $OVERWRITE_FILE
 	            ;;
 	            n|N)
 	                echo you answer n
 	                return $NOT_OVERWRITE_FILE
 	            ;;
 	            e|E)
 	                exit
 	            ;;
 	            *)
 	                echo  "fuck ,i need you correct answer!"
 	            esac
 	        done
 	    else
 	        return $OVERWRITE_FILE
 	    fi
 	}
 	CREATE_NEW_FLIE=0
 	CREATE_NEW_FILE_ERROR=1
 	EXIST_FILE=2
 	INSERT_FILE_CON=""
 	 
 	get_c_init_context(){
 	#$1 path/filename.ext
 	#$2 filename
 	    INSERT_FILE_CON="/***************\n$1\n by luckystar\n ***************/\n"
 	    INSERT_FILE_CON+="static int $2_flag =0;\n"
 	    INSERT_FILE_CON+="\nvoid $2_init(void){\n"
 	    INSERT_FILE_CON+="\tif ($2_flag) {\n\t\t//log(\"module inited..\",X);\n\t\treturn;\n\t}\n"
 	    INSERT_FILE_CON+="\t$2_flag = 1;\n"
 	    INSERT_FILE_CON+="\t//todo:module init...\n\n}\n"
 	#up is create module_init func  
 	    INSERT_FILE_CON+="\nvoid $2_destory(void){\n"
 	    INSERT_FILE_CON+="\tif (!$2_flag) {\n\t\t//log(\"module not inited..\",X);\n\t\treturn;\n\t}\n"
 	    INSERT_FILE_CON+="\t$2_flag = 0;\n"  
 	    INSERT_FILE_CON+="\t//todo:module destory...\n\n}\n"
 	#up is create module_destory func
 	}
 	 
 	get_h_init_context(){
 	#$1 path/filename.ext
 	#$2 filename
 	    INSERT_FILE_CON="#ifndef _$2_H_\n#define _$2_H_\n"
 	    INSERT_FILE_CON+="\n//ins_inc_file\n"
 	    INSERT_FILE_CON+="\n//ins_typedef_def\n"
 	    INSERT_FILE_CON+="\n//ins_def\n"
 	    INSERT_FILE_CON+="\n//ins_func_declare\n"
 	    INSERT_FILE_CON+="\n\n"
 	    INSERT_FILE_CON+="#endif //_$2_H_\n"      
 	}
 	get_test_init_context(){
 	#$1 filename
 	#$2 libname
 	    INSERT_FILE_CON="#include \"$2.h\"\n"
 	    INSERT_FILE_CON+="\n\n"
 	    INSERT_FILE_CON+="int main(int argc,char *argv[])\n"
 	    INSERT_FILE_CON+="\t$2_init();\n"
 	    INSERT_FILE_CON+="\t$2_destrory();\n"
 	    INSERT_FILE_CON+="\treturn 0;\n"
 	    INSERT_FILE_CON+="}\n"      
 	}
 	insert_file_tmp(){
 	#$1 path/filename.ext
 	#$2 filename
 	#$3 ext mode
 	    case $3 in
 	    $C_FILE_SUFFIX)
 	    get_c_init_context $1 $2
 	    ;;
 	    $H_FILE_SUFFIX)
 	    get_h_init_context $1 $2
 	    ;;
 	    $TEST_FILE_SUFFIX)
 	    get_test_init_context $4 $2
 	    esac
 	    sed  -i "a\\$INSERT_FILE_CON" $1
 	    
 	}
 	 
 	create_file_in_sub_dir(){
 	    
 	    if [ -d $1 ];then
 	        if [ $3 = $TEST_FILE_SUFFIX ]; then
 	        NEW_FILENAME=$1/test_$4_main.c
 	        else
 	        NEW_FILENAME=$1/$2$3
 	        fi
 	        check_file_exist $NEW_FILENAME
 	        if [ $? = $OVERWRITE_FILE ];then
 	            echo > $NEW_FILENAME
 	            insert_file_tmp $NEW_FILENAME $2 $3 $4
 	            echo create /$MODULE_NAME/$NEW_FILENAME file
 	            return $CREATE_NEW_FILE
 	        else
 	            return $EXIST_FILE
 	        fi
 	    else
 	        echo  /$MODULE_NAME/$1 is not directory, create_file not continue...
 	        return $CREATE_NEW_FILE_ERROR
 	        #not exit , continue done the other cmd
 	    fi
 	}
 	 
 	 
 	check_other_cmd(){
 	while [ 2 -le $# ];do
 	    case $2 in
 	    $CREATE_FILE_FLAG)
 	        shift
 	        create_file_in_sub_dir $SRC_DIR_NAME $2 $C_FILE_SUFFIX #$C_FILE_TMP
 	        create_file_in_sub_dir $INC_DIR_NAME $2 $H_FILE_SUFFIX #$H_FILE_TMP
 	        
 	        #create_file_in_sub_dir $LOG_DIR_NAME $2 $LOG_FILE_SUFFIX
 	        
 	    ;;
 	    $CREATE_TEST_FILE_FLAG)
 	        shift
 	        create_file_in_sub_dir $SRC_DIR_NAME $2 $TEST_FILE_SUFFIX  $3
 	        shift
 	        
 	        ;;
 	    *)
 	       #    echo $2" test "
 	    esac
 	        shift
 	done
 	    exit
 	}
 	create_mkdir $MODULE_NAME
 	if [ -d $MODULE_NAME ];then
 	    cd $MODULE_NAME
 	    create_mkdir $SRC_DIR_NAME
 	    create_mkdir $INC_DIR_NAME
 	    create_mkdir $BIN_DIR_NAME
 	    create_mkdir $OBJ_DIR_NAME
 	    check_other_cmd $@
 	else
 	    echo $MODULE_NAME is not directory ,could not continue...  
 	    exit
 	fi
