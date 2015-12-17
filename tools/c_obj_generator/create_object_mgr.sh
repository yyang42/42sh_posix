#!/bin/bash

BASEDIR=$(dirname $0)

export obj_name=$1
export mgr_name=$obj_name"_mgr"
export obj_plural_name=$obj_name"s"
export path_to_create=$2
export mgr_up_name=$(echo $mgr_name | tr 'a-z' 'A-Z')
export h_file_name=$obj_name"_mgr.h"
export newCfile=$obj_name"_mgr_new"
export delCfile=$obj_name"_mgr_del"
export git_root="$(git rev-parse --show-toplevel)"
export src_folder=$path_to_create/srcs/$obj_name"_mgr"
export template_folder=$BASEDIR/obj_mgr_templates

##########################CREATE FOLDER#########################################
mkdir -p $src_folder
function generate_file ()
{
	src=$1
	dst=$2
	cat $src | sed -e "s/<OBJ_NAME>/$obj_name/g" | sed -e "s/<MGR_NAME>/$mgr_name/g"  | sed -e "s/<OBJ_PLURAL_NAME>/$obj_plural_name/g" | sed -e "s/<MGR_NAME_UPPER>/$mgr_up_name/g" > $dst
}
generate_file $template_folder/obj_mgr.h includes/$h_file_name
generate_file $template_folder/obj_mgr_new.c $src_folder/$obj_name"_mgr_new.c"
generate_file $template_folder/obj_mgr_del.c $src_folder/$obj_name"_mgr_del.c"
generate_file $template_folder/obj_mgr_add.c $src_folder/$obj_name"_mgr_add.c"
generate_file $template_folder/obj_mgr_remove.c $src_folder/$obj_name"_mgr_remove.c"
generate_file $template_folder/obj_mgr_print.c $src_folder/$obj_name"_mgr_print.c"
