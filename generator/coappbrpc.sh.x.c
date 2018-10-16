#if 0
	shc Version 3.8.9b, Generic Script Compiler
	Copyright (c) 1994-2015 Francisco Rosales <frosal@fi.upm.es>

	shc -f coappbrpc.sh 
#endif

static  char data [] = 
#define      tst2_z	19
#define      tst2	((&data[3]))
	"\165\073\022\265\201\313\264\103\071\156\301\010\144\122\257\013"
	"\374\341\151\106\133\273\101\006\312\133"
#define      chk1_z	22
#define      chk1	((&data[30]))
	"\141\153\374\075\174\357\130\255\066\374\351\235\365\014\230\371"
	"\244\102\024\263\340\124\151\012\110\151\306\170\206\041"
#define      msg2_z	19
#define      msg2	((&data[57]))
	"\337\275\134\200\340\226\106\040\034\062\164\241\331\256\001\113"
	"\140\061\252\304\123"
#define      rlax_z	1
#define      rlax	((&data[77]))
	"\012"
#define      tst1_z	22
#define      tst1	((&data[83]))
	"\045\315\232\141\337\276\312\312\304\213\033\211\036\231\220\214"
	"\067\300\264\056\076\361\100\012\263\001\176"
#define      text_z	542
#define      text	((&data[160]))
	"\066\370\155\003\131\330\000\226\237\171\034\301\035\125\044\375"
	"\250\315\175\346\111\127\012\156\044\244\317\004\200\067\256\266"
	"\057\033\272\210\364\273\037\224\064\073\125\122\220\172\117\071"
	"\110\315\037\221\044\052\377\327\036\044\122\256\021\275\005\240"
	"\125\263\162\174\351\011\313\271\023\045\373\203\146\002\274\252"
	"\116\247\230\012\132\301\320\256\222\140\020\206\014\142\351\245"
	"\170\237\061\322\145\014\236\267\071\077\335\343\163\263\340\271"
	"\143\123\217\377\024\104\316\026\151\363\037\314\163\301\244\321"
	"\107\154\076\346\010\205\065\304\300\261\341\033\015\016\222\126"
	"\236\146\370\373\152\354\167\212\257\065\244\014\052\031\022\212"
	"\200\113\332\045\022\120\357\224\223\210\231\102\322\124\245\104"
	"\316\034\252\077\017\146\300\324\174\272\061\011\352\344\212\047"
	"\276\153\053\351\242\317\167\244\351\020\132\102\032\222\271\176"
	"\164\131\060\001\343\126\167\226\215\352\154\310\101\126\116\335"
	"\053\170\166\243\262\230\041\117\045\375\172\124\325\050\003\076"
	"\154\202\327\244\255\065\064\014\165\165\142\170\243\350\373\112"
	"\353\154\161\370\014\344\043\051\255\075\146\266\031\323\153\237"
	"\305\220\056\120\003\066\250\157\334\173\312\162\165\336\277\067"
	"\123\210\344\303\347\376\342\256\016\071\312\223\061\273\214\102"
	"\333\056\154\161\231\005\231\270\356\000\103\346\054\215\051\007"
	"\301\053\034\134\055\072\331\144\013\021\023\372\162\253\075\300"
	"\201\326\020\165\100\157\134\172\044\054\241\226\232\111\121\265"
	"\110\201\171\206\015\335\265\056\136\260\056\351\134\111\312\156"
	"\165\300\242\265\372\263\215\016\250\031\001\103\101\252\074\102"
	"\051\065\207\365\120\121\103\227\062\271\373\151\227\360\105\326"
	"\136\223\163\262\231\242\223\065\226\106\044\100\125\330\241\337"
	"\205\025\365\316\175\116\266\335\153\233\354\242\320\112\274\153"
	"\021\052\212\375\247\276\122\023\070\037\242\042\073\114\017\364"
	"\105\311\372\132\034\052\332\373\126\223\157\036\375\336\203\010"
	"\130\175\315\305\047\143\042\236\224\123\114\154\052\256\101\220"
	"\071\362\255\246\222\260\111\211\131\255\263\343\200\233\235\174"
	"\110\114\010\350\237\300\110\014\077\325\341\103\245\224\316\243"
	"\142\254\167\251\100\351\064\312\075\377\065\357\127\316\141\032"
	"\176\106\313\136\054\252\266\116\177\342\001\146\303\377\106\325"
	"\244\344\153\334\232\361\245\127\235\311\346\253\322\011\347\243"
	"\324\170\267\013\137\266\014\270\322\225\215\273\015\304\237\344"
	"\307\033\333\225\104\025\321\342\222\161\054\070\325\340\342\226"
	"\325\336\163\202\067\111\316\317\115\116\007\374\005\067\027\300"
	"\300\014\173\337\241\260\032\366\003\253\161\122\345\271\040\005"
	"\112\105\057\112\216\375\031\334\114\041\330\122\130\360\023\030"
	"\374\216\367\235\077\022\224\102\276\005\225\243\277\265\250\011"
	"\372\327\123\211\325\155\145\042\216\076\165\346\056\210\377\053"
	"\027\366\311\126\011\136\231\307\143\056\152\043\344\023\054"
#define      chk2_z	19
#define      chk2	((&data[796]))
	"\150\300\355\316\303\131\151\340\343\054\261\057\107\333\265\323"
	"\125\171\071\066\255\065\156\343\174"
#define      pswd_z	256
#define      pswd	((&data[839]))
	"\072\340\142\145\367\131\057\116\143\215\347\052\361\026\225\024"
	"\372\250\100\331\223\300\251\146\000\263\206\143\163\045\175\313"
	"\177\043\071\371\244\165\261\364\134\323\010\066\156\075\207\116"
	"\127\343\265\312\150\137\061\150\022\267\314\206\334\112\122\133"
	"\155\213\124\022\001\006\006\135\331\016\224\107\114\033\225\244"
	"\377\112\156\147\251\237\320\274\127\235\103\063\350\225\216\125"
	"\041\343\147\042\351\156\200\302\175\025\012\311\061\237\155\060"
	"\352\334\230\224\174\150\121\323\006\224\006\356\051\225\103\113"
	"\170\253\155\141\031\355\044\226\003\056\140\064\316\316\144\270"
	"\253\374\114\047\145\236\373\153\062\002\131\134\227\235\247\017"
	"\111\024\161\143\002\226\372\005\304\132\071\223\051\236\114\324"
	"\232\230\374\000\067\367\153\151\372\305\305\221\143\154\241\254"
	"\201\023\020\203\251\012\211\156\145\303\001\216\142\115\143\374"
	"\346\137\375\035\127\150\207\121\055\114\343\220\270\204\075\072"
	"\227\115\275\101\130\107\260\275\013\262\114\155\377\257\152\346"
	"\017\147\004\146\317\213\267\375\330\232\216\221\037\313\313\267"
	"\031\211\370\161\320\250\057\333\132\174\111\132\053\263\101\072"
	"\032\106\241\351\321\130\102\123\256\020\067\053\034\217\216\127"
	"\160\361\275\147\113\354\266\256\171\235\330\153\264\155\177"
#define      opts_z	1
#define      opts	((&data[1120]))
	"\330"
#define      msg1_z	42
#define      msg1	((&data[1128]))
	"\312\374\057\333\063\132\370\160\003\102\116\315\277\067\346\051"
	"\243\277\166\021\161\172\346\100\314\244\375\071\055\206\061\321"
	"\305\220\354\103\333\211\215\352\160\350\032\131\266\270\244\202"
	"\337\303\351\117\063\332"
#define      date_z	1
#define      date	((&data[1175]))
	"\007"
#define      shll_z	10
#define      shll	((&data[1176]))
	"\276\142\246\144\155\152\356\223\044\157\163\356"
#define      inlo_z	3
#define      inlo	((&data[1188]))
	"\111\270\302"
#define      xecc_z	15
#define      xecc	((&data[1192]))
	"\057\064\047\303\023\226\344\304\344\203\040\320\111\200\066\174"
	"\035"
#define      lsto_z	1
#define      lsto	((&data[1208]))
	"\150"/* End of data[] */;
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
