#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f coappbrpc.sh 
#endif

static  char data [] = 
#define      pswd_z	256
#define      pswd	((&data[22]))
	"\237\064\005\151\323\024\320\333\213\237\365\160\214\232\005\005"
	"\301\031\376\037\204\263\135\007\130\240\013\146\113\172\303\216"
	"\015\146\041\137\224\116\246\346\143\215\132\142\261\216\325\143"
	"\047\271\364\040\055\122\047\206\362\063\355\075\255\260\313\273"
	"\026\355\033\253\074\301\222\237\117\354\002\001\172\327\144\242"
	"\220\130\303\276\252\352\105\235\035\062\333\313\343\247\207\371"
	"\224\242\244\321\144\067\160\263\043\162\264\236\112\030\100\332"
	"\161\004\231\033\356\336\271\014\021\224\330\364\073\137\355\320"
	"\001\222\241\145\311\021\031\355\204\315\213\316\346\314\251\127"
	"\320\103\163\277\041\054\314\063\300\244\047\373\004\025\313\006"
	"\250\154\154\162\176\205\137\003\123\352\322\071\267\174\221\207"
	"\277\004\107\341\061\023\024\361\267\073\355\274\121\270\302\371"
	"\045\056\153\244\263\313\247\006\265\172\100\155\366\321\365\265"
	"\326\074\226\007\117\253\370\006\346\345\303\070\236\205\061\304"
	"\263\234\151\147\150\021\156\036\213\256\213\201\200\200\067\126"
	"\274\316\135\013\171\125\022\140\073\325\230\332\133\312\237\017"
	"\147\010\166\317\031\345\355\245\224\170\046\024\370\136\152\265"
	"\054\310\301\246\035\324\114\114\165\363\152\111\372\303\363\231"
	"\370\371\003\313\016\324\247\231\164\234\012\001\066\017\006\370"
	"\051\004\030\255\270\144\371\055\127\143\166\122\047\152\353\037"
	"\143"
#define      chk2_z	19
#define      chk2	((&data[325]))
	"\303\222\013\070\061\226\343\357\037\243\324\314\203\213\146\334"
	"\070\271\160\167\314\021\073\056\026"
#define      shll_z	10
#define      shll	((&data[347]))
	"\077\213\100\375\035\365\206\166\307\341\325"
#define      xecc_z	15
#define      xecc	((&data[358]))
	"\165\103\071\173\352\172\164\134\246\333\260\002\131\371\270\114"
	"\375"
#define      msg1_z	42
#define      msg1	((&data[383]))
	"\052\062\132\241\204\202\013\160\242\306\375\134\070\314\137\350"
	"\165\351\037\326\353\350\307\032\067\120\174\024\147\104\225\214"
	"\103\004\345\255\073\022\213\346\210\020\263\207\363\100\170\240"
	"\000\071\375\157\137\215\340\043\037\354\134\116\002"
#define      chk1_z	22
#define      chk1	((&data[439]))
	"\325\021\171\032\167\375\125\267\173\156\360\146\212\273\365\032"
	"\362\227\102\142\153\334\344\113\123\175"
#define      tst1_z	22
#define      tst1	((&data[463]))
	"\142\155\050\000\323\375\155\333\365\201\360\220\045\261\146\362"
	"\053\277\033\070\374\136\337\261"
#define      inlo_z	3
#define      inlo	((&data[485]))
	"\007\277\062"
#define      tst2_z	19
#define      tst2	((&data[488]))
	"\252\037\100\214\273\041\051\151\366\031\363\155\050\042\273\217"
	"\371\315\056\356"
#define      msg2_z	19
#define      msg2	((&data[512]))
	"\351\172\076\015\136\053\036\343\175\131\136\371\356\013\034\303"
	"\137\004\210\371\366\136\142\231"
#define      date_z	1
#define      date	((&data[532]))
	"\044"
#define      lsto_z	1
#define      lsto	((&data[533]))
	"\246"
#define      rlax_z	1
#define      rlax	((&data[534]))
	"\144"
#define      text_z	542
#define      text	((&data[661]))
	"\106\006\227\264\107\054\174\052\106\307\031\317\264\167\271\056"
	"\265\307\307\340\060\257\016\060\113\146\005\370\066\363\055\175"
	"\372\305\062\101\362\256\154\070\165\206\010\051\375\301\130\262"
	"\211\040\223\271\317\242\352\032\010\357\023\077\343\101\275\335"
	"\006\357\037\371\236\213\061\023\021\071\075\017\373\226\301\204"
	"\266\125\076\205\367\050\240\377\027\264\077\372\365\374\330\374"
	"\353\367\365\211\203\047\235\225\140\333\244\133\162\146\340\050"
	"\273\036\256\262\106\116\262\136\003\361\131\370\355\061\130\075"
	"\134\366\034\267\157\143\052\146\146\054\262\334\004\266\105\202"
	"\373\013\174\035\354\152\301\364\253\265\122\064\350\217\372\236"
	"\050\306\317\326\356\141\246\201\142\021\326\013\074\144\275\032"
	"\172\100\130\174\204\344\322\320\163\033\176\021\111\275\261\004"
	"\156\277\212\146\336\010\242\023\032\173\336\006\201\102\125\123"
	"\071\024\357\332\300\007\134\173\023\116\167\027\023\011\234\355"
	"\057\257\024\146\163\033\333\325\136\223\232\260\251\037\204\227"
	"\337\036\270\163\366\145\162\064\351\242\127\354\325\062\247\346"
	"\056\227\313\267\266\217\347\270\117\116\051\067\157\151\276\342"
	"\261\124\062\273\054\253\372\326\165\214\144\317\356\140\253\267"
	"\172\127\123\326\304\066\230\161\217\330\051\222\223\374\152\213"
	"\013\107\077\071\255\172\072\006\154\115\257\006\057\275\021\260"
	"\243\065\106\077\367\170\023\261\276\023\300\047\372\307\121\317"
	"\236\033\315\076\334\266\021\200\023\333\317\217\172\331\212\015"
	"\261\202\243\375\047\367\351\022\220\225\066\322\301\112\011\033"
	"\335\171\344\036\040\047\326\122\255\131\107\017\113\306\201\120"
	"\066\261\240\340\077\025\230\356\261\107\063\017\005\262\116\326"
	"\256\046\122\165\027\032\345\216\264\150\144\343\101\377\311\035"
	"\326\375\153\313\073\177\361\176\273\213\237\054\010\153\053\243"
	"\036\107\254\035\232\120\006\325\312\163\275\375\216\104\121\157"
	"\010\055\031\203\034\266\340\353\041\336\133\127\313\236\236\223"
	"\332\315\221\271\367\257\014\011\035\026\003\251\174\212\150\240"
	"\322\150\336\147\207\251\312\134\106\044\276\026\012\136\353\365"
	"\213\140\166\165\033\117\240\037\326\115\152\141\022\100\102\275"
	"\050\057\004\017\124\272\200\044\211\340\004\167\030\364\277\347"
	"\226\273\174\027\213\234\253\231\107\003\106\002\354\022\115\265"
	"\163\251\207\376\147\221\042\021\017\024\163\103\343\341\127\234"
	"\332\343\054\000\177\123\223\164\331\224\140\053\202\372\360\367"
	"\322\100\353\340\343\032\155\065\117\024\342\072\220\356\335\261"
	"\310\044\303\375\143\230\014\060\274\373\213\043\265\134\064\021"
	"\365\033\253\371\056\072\277\162\065\116\177\023\262\344\115\062"
	"\134\000\236\020\307\352\255\016\344\064\110\334\354\040\341\206"
	"\322\325\037\166\212\243\017\203\106\326\151\067\032\231\271\242"
	"\377\270\304\341\035\077\206\321\275\050\121\002\365\331\050\352"
	"\143\254\022\001\101\162\335\345\316\117\113\256\170\007\315\046"
	"\271\023\165\153\162\170\135\313"
#define      opts_z	1
#define      opts	((&data[1231]))
	"\347"/* End of data[] */;
#define      hide_z	4096
#define DEBUGEXEC	0	/* Define as 1 to debug execvp calls */
#define TRACEABLE	0	/* Define as 1 to enable ptrace the executable */

/* rtc.c */

#include <sys/stat.h>
#include <sys/types.h>

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

/* 'Alleged RC4' */

static unsigned char stte[256], indx, jndx, kndx;

/*
 * Reset arc4 stte. 
 */
void stte_0(void)
{
	indx = jndx = kndx = 0;
	do {
		stte[indx] = indx;
	} while (++indx);
}

/*
 * Set key. Can be used more than once. 
 */
void key(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		do {
			tmp = stte[indx];
			kndx += tmp;
			kndx += ptr[(int)indx % len];
			stte[indx] = stte[kndx];
			stte[kndx] = tmp;
		} while (++indx);
		ptr += 256;
		len -= 256;
	}
}

/*
 * Crypt data. 
 */
void arc4(void * str, int len)
{
	unsigned char tmp, * ptr = (unsigned char *)str;
	while (len > 0) {
		indx++;
		tmp = stte[indx];
		jndx += tmp;
		stte[indx] = stte[jndx];
		stte[jndx] = tmp;
		tmp += stte[indx];
		*ptr ^= stte[tmp];
		ptr++;
		len--;
	}
}

/* End of ARC4 */

/*
 * Key with file invariants. 
 */
int key_with_file(char * file)
{
	struct stat statf[1];
	struct stat control[1];

	if (stat(file, statf) < 0)
		return -1;

	/* Turn on stable fields */
	memset(control, 0, sizeof(control));
	control->st_ino = statf->st_ino;
	control->st_dev = statf->st_dev;
	control->st_rdev = statf->st_rdev;
	control->st_uid = statf->st_uid;
	control->st_gid = statf->st_gid;
	control->st_size = statf->st_size;
	control->st_mtime = statf->st_mtime;
	control->st_ctime = statf->st_ctime;
	key(control, sizeof(control));
	return 0;
}

#if DEBUGEXEC
void debugexec(char * sh11, int argc, char ** argv)
{
	int i;
	fprintf(stderr, "shll=%s\n", sh11 ? sh11 : "<null>");
	fprintf(stderr, "argc=%d\n", argc);
	if (!argv) {
		fprintf(stderr, "argv=<null>\n");
	} else { 
		for (i = 0; i <= argc ; i++)
			fprintf(stderr, "argv[%d]=%.60s\n", i, argv[i] ? argv[i] : "<null>");
	}
}
#endif /* DEBUGEXEC */

void rmarg(char ** argv, char * arg)
{
	for (; argv && *argv && *argv != arg; argv++);
	for (; argv && *argv; argv++)
		*argv = argv[1];
}

int chkenv(int argc)
{
	char buff[512];
	unsigned long mask, m;
	int l, a, c;
	char * string;
	extern char ** environ;

	mask  = (unsigned long)&chkenv;
	mask ^= (unsigned long)getpid() * ~mask;
	sprintf(buff, "x%lx", mask);
	string = getenv(buff);
#if DEBUGEXEC
	fprintf(stderr, "getenv(%s)=%s\n", buff, string ? string : "<null>");
#endif
	l = strlen(buff);
	if (!string) {
		/* 1st */
		sprintf(&buff[l], "=%lu %d", mask, argc);
		putenv(strdup(buff));
		return 0;
	}
	c = sscanf(string, "%lu %d%c", &m, &a, buff);
	if (c == 2 && m == mask) {
		/* 3rd */
		rmarg(environ, &string[-l - 1]);
		return 1 + (argc - a);
	}
	return -1;
}

#if !defined(TRACEABLE)

#define _LINUX_SOURCE_COMPAT
#include <sys/ptrace.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

#if !defined(PTRACE_ATTACH) && defined(PT_ATTACH)
#	define PTRACE_ATTACH	PT_ATTACH
#endif
void untraceable(char * argv0)
{
	char proc[80];
	int pid, mine;

	switch(pid = fork()) {
	case  0:
		pid = getppid();
		/* For problematic SunOS ptrace */
#if defined(__FreeBSD__)
		sprintf(proc, "/proc/%d/mem", (int)pid);
#else
		sprintf(proc, "/proc/%d/as",  (int)pid);
#endif
		close(0);
		mine = !open(proc, O_RDWR|O_EXCL);
		if (!mine && errno != EBUSY)
			mine = !ptrace(PTRACE_ATTACH, pid, 0, 0);
		if (mine) {
			kill(pid, SIGCONT);
		} else {
			perror(argv0);
			kill(pid, SIGKILL);
		}
		_exit(mine);
	case -1:
		break;
	default:
		if (pid == waitpid(pid, 0, 0))
			return;
	}
	perror(argv0);
	_exit(1);
}
#endif /* !defined(TRACEABLE) */

char * xsh(int argc, char ** argv)
{
	char * scrpt;
	int ret, i, j;
	char ** varg;
	char * me = argv[0];

	stte_0();
	 key(pswd, pswd_z);
	arc4(msg1, msg1_z);
	arc4(date, date_z);
	if (date[0] && (atoll(date)<time(NULL)))
		return msg1;
	arc4(shll, shll_z);
	arc4(inlo, inlo_z);
	arc4(xecc, xecc_z);
	arc4(lsto, lsto_z);
	arc4(tst1, tst1_z);
	 key(tst1, tst1_z);
	arc4(chk1, chk1_z);
	if ((chk1_z != tst1_z) || memcmp(tst1, chk1, tst1_z))
		return tst1;
	ret = chkenv(argc);
	arc4(msg2, msg2_z);
	if (ret < 0)
		return msg2;
	varg = (char **)calloc(argc + 10, sizeof(char *));
	if (!varg)
		return 0;
	if (ret) {
		arc4(rlax, rlax_z);
		if (!rlax[0] && key_with_file(shll))
			return shll;
		arc4(opts, opts_z);
		arc4(text, text_z);
		arc4(tst2, tst2_z);
		 key(tst2, tst2_z);
		arc4(chk2, chk2_z);
		if ((chk2_z != tst2_z) || memcmp(tst2, chk2, tst2_z))
			return tst2;
		/* Prepend hide_z spaces to script text to hide it. */
		scrpt = malloc(hide_z + text_z);
		if (!scrpt)
			return 0;
		memset(scrpt, (int) ' ', hide_z);
		memcpy(&scrpt[hide_z], text, text_z);
	} else {			/* Reexecute */
		if (*xecc) {
			scrpt = malloc(512);
			if (!scrpt)
				return 0;
			sprintf(scrpt, xecc, me);
		} else {
			scrpt = me;
		}
	}
	j = 0;
	varg[j++] = argv[0];		/* My own name at execution */
	if (ret && *opts)
		varg[j++] = opts;	/* Options on 1st line of code */
	if (*inlo)
		varg[j++] = inlo;	/* Option introducing inline code */
	varg[j++] = scrpt;		/* The script itself */
	if (*lsto)
		varg[j++] = lsto;	/* Option meaning last option */
	i = (ret > 1) ? ret : 0;	/* Args numbering correction */
	while (i < argc)
		varg[j++] = argv[i++];	/* Main run-time arguments */
	varg[j] = 0;			/* NULL terminated array */
#if DEBUGEXEC
	debugexec(shll, j, varg);
#endif
	execvp(shll, varg);
	return shll;
}

int main(int argc, char ** argv)
{
#if DEBUGEXEC
	debugexec("main", argc, argv);
#endif
#if !defined(TRACEABLE)
	untraceable(argv[0]);
#endif
	argv[1] = xsh(argc, argv);
	fprintf(stderr, "%s%s%s: %s\n", argv[0],
		errno ? ": " : "",
		errno ? strerror(errno) : "",
		argv[1] ? argv[1] : "<null>"
	);
	return 1;
}
