/*
 * =========================================================================
 *
 *       Filename:  types.h
 *
 *    Description:  Define types for list
 *
 *        Version:  1.0
 *        Created:  04/07/2014 06:42:01 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Youngcy (), youngcy.youngcy@gmail.com
 *   Organization:  
 *
 * =========================================================================
 */

struct list_head {
	struct list_head *next, *prev;
};
