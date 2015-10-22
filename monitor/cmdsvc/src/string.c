/*
 * Copyright (c) 2015 Du Huanpeng <u74147@gmail.com>
 * origin: monitor/cmdsvc/src/string.c
 * slow and simple libray rouines.
 * FIXME: not tested.
 */
/*
 *----------------------------------------------------------------------
 *    T-Kernel 2.0 Software Package
 *
 *    Copyright 2011 by Ken Sakamura.
 *    This software is distributed under the latest version of T-License 2.x.
 *----------------------------------------------------------------------
 *
 *    Released by T-Engine Forum(http://www.t-engine.org/) at 2011/05/17.
 *    Added by T-Engine Forum at 2013/03/11.
 *    Modified by TRON Forum(http://www.tron.org/) at 2015/06/01.
 *
 *----------------------------------------------------------------------
 */

/*
 *	string.c
 *	Standard string / memory operations used for t-monitor
 */

#include <tmonitor.h>


/*
 * memset : fill memory area
 */
void* memset( void *s, int c, size_t n )
{
	int i;
	char *mem = s;
	for(i=0; i<n; i++) {
		mem[i] = c;
	}
	return s;
}

/*
 * memcmp : perform memory comparison
 */
int memcmp( const void *s1, const void *s2, size_t n )
{
	const unsigned char	*p1 = s1;
	const unsigned char	*p2 = s2;
	int rc;
	while( *p1 == *p2 && n--) {
		p1++;
		p2++;
	}
	rc = *p1 - *p2;
	return rc;
}

/*
 * memcpy : copy memory
 */
void* memcpy( void *dst, const void *src, size_t n )
{
	int i;
	char *to = dst;
	const char *from = src;
	for(i=0; i<n; i++) {
		to[i] = from[i];
	}
	return dst;
}

/*
 * memmove : move memory
 */
void* memmove( void *dst, const void *src, size_t n )
{
	int i;
	char *to = dst;
	const char *from = src;
	if(src < dst) {
		for(i=0; i<n; i++){
			to[i] = from[i];
		}
	}
	else if(src > dst) {
		i = n;
		while(i--) {
			to[i] = from[i];
		}
	}
	/* do nothing if src == dst. */
	return dst;
}

/*
 * strlen : get text string length
 */
size_t strlen( const char *s )
{
	size_t rc = 0;
	while(s[rc++]);
	return rc;
}

/*
 * strcmp : perform text string comparison
 */
int strcmp( const char *s1, const char *s2 )
{
	int rc;
	while(*s1 && *s1 == *s2) {
		s1++;
		s2++;
	}
	rc = *s1 - *s2;
	return rc;
}

/*
 * strncmp : perform text string comparison of specified length
 */
int strncmp( const char *s1, const char *s2, size_t n )
{
    int rc;
    while(*s1 && *s1 == *s2 && n) {
	s1++;
	s2++;
	n--;
    };
    rc = *s1 - *s2;
    return rc;
}

/*
 * strcpy : copy text string
 */
char* strcpy( char *dst, const char *src )
{
	while((*dst = *src)) {
		dst++;
		src++;
	}
	return dst;
}

/*
 * strncpy : copy text string of specified length
 */
char* strncpy( char *dst, const char *src, size_t n )
{
	while((*dst = *src) && n) {
		dst++;
		src++;
		n--;
	}
	return dst;
}

