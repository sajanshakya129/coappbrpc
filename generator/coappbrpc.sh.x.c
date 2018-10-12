#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f coappbrpc.sh 
#endif

static  char data [] = 
#define      inlo_z	3
#define      inlo	((&data[0]))
	"\043\141\155"
#define      chk1_z	22
#define      chk1	((&data[5]))
	"\112\300\153\254\030\265\217\102\161\142\376\371\046\251\202\034"
	"\372\110\001\060\101\363\233\000\061\202"
#define      xecc_z	15
#define      xecc	((&data[29]))
	"\045\237\301\317\071\375\005\312\222\056\150\266\115\243\114\204"
#define      shll_z	10
#define      shll	((&data[46]))
	"\102\153\056\340\312\201\157\372\225\035\044\142"
#define      text_z	310
#define      text	((&data[77]))
	"\215\161\103\132\005\243\176\317\112\314\327\247\142\100\021\254"
	"\000\103\056\133\253\075\071\230\047\027\177\366\262\377\345\325"
	"\071\127\102\330\304\223\243\204\345\067\331\113\224\120\345\010"
	"\167\353\267\207\360\350\163\113\013\271\073\352\221\160\131\074"
	"\252\274\011\263\374\137\253\127\132\161\142\230\245\220\165\261"
	"\365\354\372\120\336\217\246\214\241\357\121\225\003\154\153\177"
	"\063\345\315\262\165\201\015\240\015\075\325\002\070\033\272\354"
	"\127\012\335\122\241\374\005\053\065\251\246\151\324\273\364\072"
	"\363\276\170\164\145\071\053\200\041\212\025\046\210\102\100\356"
	"\130\350\036\113\064\351\262\166\307\130\335\210\314\023\334\061"
	"\103\117\175\313\206\302\140\107\312\143\350\055\114\317\126\011"
	"\346\036\106\100\062\001\055\203\363\146\176\203\321\031\310\077"
	"\013\124\043\202\223\113\305\212\130\243\355\050\222\150\366\240"
	"\162\344\221\355\111\250\225\361\213\154\165\225\174\047\330\126"
	"\111\353\115\020\100\326\243\311\334\065\336\343\277\244\300\202"
	"\362\350\075\171\132\167\155\330\340\104\327\036\334\066\152\375"
	"\062\130\315\075\130\352\010\077\372\101\350\126\365\132\164\071"
	"\351\207\166\270\045\357\171\177\302\235\277\202\025\315\061\362"
	"\204\046\235\265\103\177\267\177\076\320\036\030\272\066\322\165"
	"\342\206\114\300\117\375\100\366\126\266\102\110\125\301\017\315"
	"\263\003\346\246\144\362\236\131\237\207\173\216\337\265\376\117"
	"\370\140\041\072\006\257\253\112\011\260\355\210\200\067\124\127"
	"\337\267\230\360\144\230\063\222\363\257\041\323\145\037\043\135"
	"\200\105\227\207\364\102\321\375\363\276\206\163"
#define      chk2_z	19
#define      chk2	((&data[441]))
	"\325\222\142\306\376\141\121\071\112\271\202\201\262\320\265\150"
	"\035\114\062\015\046\027\344\366\373\372"
#define      msg2_z	19
#define      msg2	((&data[467]))
	"\252\302\017\312\336\165\137\265\062\072\046\177\066\006\233\352"
	"\336\236\132\164\013\331\304\345\154\113"
#define      date_z	1
#define      date	((&data[489]))
	"\213"
#define      msg1_z	42
#define      msg1	((&data[493]))
	"\035\071\142\171\152\114\123\177\360\163\061\306\021\033\113\000"
	"\333\131\260\072\021\360\073\346\120\163\350\275\246\055\034\216"
	"\003\163\153\065\242\212\300\264\130\300\256\301\130\243\254\131"
	"\176\167\057\021"
#define      tst2_z	19
#define      tst2	((&data[546]))
	"\326\360\221\306\267\170\224\272\243\111\237\105\111\102\154\214"
	"\043\262\367\051\254\230\256"
#define      rlax_z	1
#define      rlax	((&data[565]))
	"\317"
#define      opts_z	1
#define      opts	((&data[566]))
	"\157"
#define      lsto_z	1
#define      lsto	((&data[567]))
	"\062"
#define      tst1_z	22
#define      tst1	((&data[568]))
	"\376\355\105\201\026\124\325\343\256\070\135\332\077\201\326\101"
	"\050\031\211\115\175\072\141\310\326\233"
#define      pswd_z	256
#define      pswd	((&data[625]))
	"\204\370\277\264\012\231\252\022\160\233\243\066\066\340\277\340"
	"\347\056\370\071\310\023\135\201\164\046\130\017\121\322\127\273"
	"\363\207\203\043\362\242\246\205\342\246\172\372\134\221\005\243"
	"\024\364\045\350\310\011\263\140\245\202\010\207\207\352\102\173"
	"\162\306\236\145\151\105\353\113\353\145\106\110\366\113\353\013"
	"\100\020\363\011\032\247\151\277\051\162\107\260\135\211\053\317"
	"\120\312\065\271\017\040\005\373\205\113\103\173\226\057\206\327"
	"\100\172\340\132\041\112\032\113\274\141\373\031\352\047\351\073"
	"\362\036\365\002\077\372\375\304\105\101\100\334\160\307\263\260"
	"\101\224\013\143\336\045\256\232\206\252\264\161\321\236\254\303"
	"\275\241\306\374\233\303\301\341\005\001\275\165\310\161\046\012"
	"\005\061\155\344\126\034\177\334\306\063\115\227\321\372\133\217"
	"\233\042\213\067\345\114\031\353\116\327\140\026\110\207\041\116"
	"\270\217\062\017\253\261\354\161\345\072\011\267\064\145\106\320"
	"\207\321\010\155\036\041\130\154\370\271\203\101\100\245\217\371"
	"\064\302\010\337\164\365\121\132\060\133\021\145\300\127\065\110"
	"\051\076\265\107\137\015\264\130\306\067\231\007\335\051\000\021"
	"\354\011\361\141\377\103\273\057\236\314\224\137\044\312\247\325"
	"\313\027\211\325\261\064\347\041\317\213\127\005\154\027\346\123"
	"\105"/* End of data[] */;
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
