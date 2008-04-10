/* Copyright (c) 2006-2008 Jonas Fonseca <fonseca@diku.dk>
/* ncurses(3): Must be defined to have extended wide-character functions. */
#define _XOPEN_SOURCE_EXTENDED

static size_t utf8_length(const char *string, size_t max_width, int *trimmed, bool reserve);
#define ID_COLS		8
#define NUMBER_INTERVAL	5
#define NULL_ID		"0000000000000000000000000000000000000000"

	"git show --pretty=fuller --no-color --root --patch-with-stat --find-copies-harder -C %s 2>/dev/null"
	"git log --no-color --topo-order --parents --boundary --pretty=raw %s 2>/dev/null"
#define TIG_BLAME_CMD	""
	unsigned int head:1;	/* Is it the current HEAD? */
	unsigned int ltag:1;	/* If so, is the tag local? */
	unsigned int tracked:1;	/* Is it the remote for the current HEAD? */
	REQ_(VIEW_BLAME,	"Show blame view"), \
	REQ_(MAXIMIZE,		"Maximize the current view"), \
	REQ_(TOGGLE_DATE,	"Toggle date display"), \
	REQ_(TOGGLE_AUTHOR,	"Toggle author display"), \
	REQ_(TOGGLE_REFS,	"Toggle reference display (tags/branches)"), \
"   or: tig blame  [rev] path\n"
"  -h, --help      Show help message and exit";
static bool opt_date			= TRUE;
static bool opt_author			= TRUE;
static bool opt_show_refs		= TRUE;
static char opt_file[SIZEOF_STR]	= "";
static char opt_ref[SIZEOF_REF]		= "";
static char opt_head[SIZEOF_REF]	= "";
static char opt_remote[SIZEOF_REF]	= "";
static bool opt_no_head			= TRUE;
	size_t buf_size;
	char *subcommand;
	bool seen_dashdash = FALSE;
	if (!isatty(STDIN_FILENO)) {
		opt_request = REQ_VIEW_PAGER;
		opt_pipe = stdin;
		return TRUE;
	}
	if (argc <= 1)
		return TRUE;
	subcommand = argv[1];
	if (!strcmp(subcommand, "status") || !strcmp(subcommand, "-S")) {
		opt_request = REQ_VIEW_STATUS;
		if (!strcmp(subcommand, "-S"))
			warn("`-S' has been deprecated; use `tig status' instead");
		if (argc > 2)
			warn("ignoring arguments after `%s'", subcommand);
		return TRUE;
	} else if (!strcmp(subcommand, "blame")) {
		opt_request = REQ_VIEW_BLAME;
		if (argc <= 2 || argc > 4)
			die("invalid number of options to blame\n\n%s", usage);
		i = 2;
		if (argc == 4) {
			string_ncopy(opt_ref, argv[i], strlen(argv[i]));
		string_ncopy(opt_file, argv[i], strlen(argv[i]));
		return TRUE;
	} else if (!strcmp(subcommand, "show")) {
		opt_request = REQ_VIEW_DIFF;
	} else if (!strcmp(subcommand, "log") || !strcmp(subcommand, "diff")) {
		opt_request = subcommand[0] == 'l'
			    ? REQ_VIEW_LOG : REQ_VIEW_DIFF;
		warn("`tig %s' has been deprecated", subcommand);
	} else {
		subcommand = NULL;
	if (!subcommand)
		/* XXX: This is vulnerable to the user overriding
		 * options required for the main view parser. */
		string_copy(opt_cmd, "git log --no-color --pretty=raw --boundary --parents");
	else
		string_format(opt_cmd, "git %s", subcommand);
	buf_size = strlen(opt_cmd);
	for (i = 1 + !!subcommand; i < argc; i++) {
		char *opt = argv[i];
		if (seen_dashdash || !strcmp(opt, "--")) {
			seen_dashdash = TRUE;
		} else if (!strcmp(opt, "-v") || !strcmp(opt, "--version")) {
			printf("tig version %s\n", TIG_VERSION);
			return FALSE;
		} else if (!strcmp(opt, "-h") || !strcmp(opt, "--help")) {
			printf("%s\n", usage);
			return FALSE;
		opt_cmd[buf_size++] = ' ';
		buf_size = sq_quote(opt_cmd, buf_size, opt);
	opt_cmd[buf_size] = 0;
LINE(DELIMITER,	   "",			COLOR_MAGENTA,	COLOR_DEFAULT,	0), \
LINE(DATE,         "",			COLOR_BLUE,	COLOR_DEFAULT,	0), \
LINE(LINE_NUMBER,  "",			COLOR_CYAN,	COLOR_DEFAULT,	0), \
LINE(MAIN_LOCAL_TAG,"",			COLOR_MAGENTA,	COLOR_DEFAULT,	0), \
LINE(MAIN_REMOTE,  "",			COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(MAIN_TRACKED, "",			COLOR_YELLOW,	COLOR_DEFAULT,	A_BOLD), \
LINE(MAIN_REF,     "",			COLOR_CYAN,	COLOR_DEFAULT,	0), \
LINE(MAIN_HEAD,    "",			COLOR_CYAN,	COLOR_DEFAULT,	A_BOLD), \
LINE(STAT_HEAD,    "",			COLOR_YELLOW,	COLOR_DEFAULT,	0), \
LINE(STAT_UNTRACKED,"",			COLOR_MAGENTA,	COLOR_DEFAULT,	0), \
LINE(BLAME_ID,     "",			COLOR_MAGENTA,	COLOR_DEFAULT,	0)
get_line_info(char *name)
	size_t namelen = strlen(name);
	unsigned int dirty:1;
	{ 'B',		REQ_VIEW_BLAME },
	{ KEY_F(5),	REQ_REFRESH },
	{ 'O',		REQ_MAXIMIZE },
	{ 'D',		REQ_TOGGLE_DATE },
	{ 'A',		REQ_TOGGLE_AUTHOR },
	{ 'F',		REQ_TOGGLE_REFS },
	KEYMAP_(BLAME), \
	info = get_line_info(argv[0]);
		if (!string_enum_compare(argv[0], "main-delim", strlen("main-delim"))) {
			info = get_line_info("delimiter");

		} else if (!string_enum_compare(argv[0], "main-date", strlen("main-date"))) {
			info = get_line_info("date");

		} else {
			config_msg = "Unknown color name";
			return ERR;
		}
static bool parse_bool(const char *s)
{
	return (!strcmp(s, "1") || !strcmp(s, "true") ||
		!strcmp(s, "yes")) ? TRUE : FALSE;
}

	if (!strcmp(argv[0], "show-author")) {
		opt_author = parse_bool(argv[2]);
		return OK;
	}

	if (!strcmp(argv[0], "show-date")) {
		opt_date = parse_bool(argv[2]);
		return OK;
	}

		opt_rev_graph = parse_bool(argv[2]);
		return OK;
	}

	if (!strcmp(argv[0], "show-refs")) {
		opt_show_refs = parse_bool(argv[2]);
		return OK;
	}

	if (!strcmp(argv[0], "show-line-numbers")) {
		opt_line_number = parse_bool(argv[2]);
	bool git_dir;		/* Whether the view requires a git directory. */
	size_t lines;		/* Total number of lines */
	size_t line_alloc;	/* Total number of allocated lines */
	size_t line_size;	/* Total number of used lines */
static struct view_ops blame_ops;
#define VIEW_STR(name, cmd, env, ref, ops, map, git) \
	{ name, cmd, #env, ref, ops, map, git }
#define VIEW_(id, name, ops, git, ref) \
	VIEW_STR(name, TIG_##id##_CMD,  TIG_##id##_CMD, ref, ops, KEYMAP_##id, git)
	VIEW_(MAIN,   "main",   &main_ops,   TRUE,  ref_head),
	VIEW_(DIFF,   "diff",   &pager_ops,  TRUE,  ref_commit),
	VIEW_(LOG,    "log",    &pager_ops,  TRUE,  ref_head),
	VIEW_(TREE,   "tree",   &tree_ops,   TRUE,  ref_commit),
	VIEW_(BLOB,   "blob",   &blob_ops,   TRUE,  ref_blob),
	VIEW_(BLAME,  "blame",  &blame_ops,  TRUE,  ref_commit),
	VIEW_(HELP,   "help",   &help_ops,   FALSE, ""),
	VIEW_(PAGER,  "pager",  &pager_ops,  FALSE, "stdin"),
	VIEW_(STATUS, "status", &status_ops, TRUE,  ""),
	VIEW_(STAGE,  "stage",	&stage_ops,  TRUE,  ""),
#define VIEW(req) 	(&views[(req) - REQ_OFFSET - 1])
#define VIEW_REQ(view)	((view) - views + REQ_OFFSET + 1)
static int
draw_text(struct view *view, const char *string, int max_len,
	  bool use_tilde, bool selected)
{
	int len = 0;
	int trimmed = FALSE;

	if (max_len <= 0)
		return 0;

	if (opt_utf8) {
		len = utf8_length(string, max_len, &trimmed, use_tilde);
	} else {
		len = strlen(string);
		if (len > max_len) {
			if (use_tilde) {
				max_len -= 1;
			}
			len = max_len;
			trimmed = TRUE;
		}
	}

	waddnstr(view->win, string, len);
	if (trimmed && use_tilde) {
		if (!selected)
			wattrset(view->win, get_line_attr(LINE_DELIMITER));
		waddch(view->win, '~');
		len++;
	}

	return len;
}

static int
draw_lineno(struct view *view, unsigned int lineno, int max, bool selected)
{
	static char fmt[] = "%1ld";
	char number[10] = "          ";
	int digits3 = view->digits < 3 ? 3 : view->digits;
	int max_number = MIN(digits3, STRING_SIZE(number));
	bool showtrimmed = FALSE;
	int col;

	lineno += view->offset + 1;
	if (lineno == 1 || (lineno % opt_num_interval) == 0) {
		if (view->digits <= 9)
			fmt[1] = '0' + digits3;

		if (!string_format(number, fmt, lineno))
			number[0] = 0;
		showtrimmed = TRUE;
	}

	if (max < max_number)
		max_number = max;

	if (!selected)
		wattrset(view->win, get_line_attr(LINE_LINE_NUMBER));
	col = draw_text(view, number, max_number, showtrimmed, selected);
	if (col < max) {
		if (!selected)
			wattrset(view->win, A_NORMAL);
		waddch(view->win, ACS_VLINE);
		col++;
	}
	if (col < max) {
		waddch(view->win, ' ');
		col++;
	}

	return col;
}

static int
draw_date(struct view *view, struct tm *time, int max, bool selected)
{
	char buf[DATE_COLS];
	int col;
	int timelen = 0;

	if (max > DATE_COLS)
		max = DATE_COLS;
	if (time)
		timelen = strftime(buf, sizeof(buf), DATE_FORMAT, time);
	if (!timelen) {
		memset(buf, ' ', sizeof(buf) - 1);
		buf[sizeof(buf) - 1] = 0;
	}

	if (!selected)
		wattrset(view->win, get_line_attr(LINE_DATE));
	col = draw_text(view, buf, max, FALSE, selected);
	if (col < max) {
		if (!selected)
			wattrset(view->win, get_line_attr(LINE_DEFAULT));
		waddch(view->win, ' ');
		col++;
	}

	return col;
}

	wmove(view->win, lineno, 0);

		wchgat(view->win, -1, 0, LINE_CURSOR, NULL);
		wattrset(view->win, get_line_attr(LINE_CURSOR));
static void
redraw_view_dirty(struct view *view)
{
	bool dirty = FALSE;
	int lineno;

	for (lineno = 0; lineno < view->height; lineno++) {
		struct line *line = &view->line[view->offset + lineno];

		if (!line->dirty)
			continue;
		line->dirty = 0;
		dirty = TRUE;
		if (!draw_view_line(view, lineno))
			break;
	}

	if (!dirty)
		return;
	redrawwin(view->win);
	if (input_mode)
		wnoutrefresh(view->win);
	else
		wrefresh(view->win);
}

#define ITEM_CHUNK_SIZE 256
static void *
realloc_items(void *mem, size_t *size, size_t new_size, size_t item_size)
{
	size_t num_chunks = *size / ITEM_CHUNK_SIZE;
	size_t num_chunks_new = (new_size + ITEM_CHUNK_SIZE - 1) / ITEM_CHUNK_SIZE;

	if (mem == NULL || num_chunks != num_chunks_new) {
		*size = num_chunks_new * ITEM_CHUNK_SIZE;
		mem = realloc(mem, *size * item_size);
	}

	return mem;
}

	size_t alloc = view->line_alloc;
	struct line *tmp = realloc_items(view->line, &alloc, line_size,
					 sizeof(*view->line));
	view->line_alloc = alloc;
	if (view == VIEW(REQ_VIEW_BLAME))
		redraw_view_dirty(view);

	if (view->ops->read(view, NULL))
		end_update(view);
	OPEN_NOMAXIMIZE = 8,	/* Do not maximize the current view. */
	bool nomaximize = !!(flags & OPEN_NOMAXIMIZE);
	if (view->git_dir && !opt_git_dir[0]) {
		report("The %s view is disabled in pager view", view->name);
	} else if (!nomaximize) {
	if (view->ops->open) {
		if (!view->ops->open(view)) {
			report("Failed to load %s view", view->name);
			return;
		}

	} else if ((reload || strcmp(view->vid, view->id)) &&
		   !begin_update(view)) {
		report("Failed to load %s view", view->name);
		return;
	}

		werase(view->win);
		/* FIXME: When all views can refresh always do this. */
		if (view == VIEW(REQ_VIEW_STATUS) ||
		    view == VIEW(REQ_VIEW_STAGE))
			request = REQ_REFRESH;
		else
			return TRUE;
	case REQ_VIEW_BLAME:
		if (!opt_file[0]) {
			report("No file chosen, press %s to open tree view",
			       get_key(REQ_VIEW_TREE));
			break;
		}
		open_view(view, request, OPEN_DEFAULT);
		break;

		   (view == VIEW(REQ_VIEW_DIFF) &&
		     view->parent == VIEW(REQ_VIEW_BLAME)) ||
	case REQ_MAXIMIZE:
		if (displayed_views() == 2)
			open_view(view, VIEW_REQ(view), OPEN_DEFAULT);
		break;

	case REQ_TOGGLE_DATE:
		opt_date = !opt_date;
		redraw_display();
		break;

	case REQ_TOGGLE_AUTHOR:
		opt_author = !opt_author;
		redraw_display();
		break;

	case REQ_TOGGLE_REFS:
		opt_show_refs = !opt_show_refs;
		redraw_display();
		break;

	static char spaces[] = "                    ";
	int col = 0;
	if (opt_line_number) {
		col += draw_lineno(view, lineno, view->width, selected);
		if (col >= view->width)
			return TRUE;
	if (!selected)
		wattrset(view->win, get_line_attr(line->type));
	if (opt_tab_size < TABSIZE) {
		int col_offset = col;
		col = 0;
		draw_text(view, text, view->width - col, TRUE, selected);
	char *commit_id = (char *)line->data + STRING_SIZE("commit ");
		char *text = (char *)line->data + STRING_SIZE("commit ");
static char *
tree_path(struct line *line)
{
	char *path = line->data;

	return path + SIZEOF_TREE_ATTR;
}

	if (!text)
		return TRUE;
		char *path1 = tree_path(line);
	if (request == REQ_VIEW_BLAME) {
		char *filename = tree_path(line);

		if (line->type == LINE_TREE_DIR) {
			report("Cannot show blame for directory %s", opt_path);
			return REQ_NONE;
		}

		string_copy(opt_ref, view->vid);
		string_format(opt_file, "%s%s", opt_path, filename);
		return request;
	}
			char *basename = tree_path(line);
	char *text = (char *)line->data + STRING_SIZE("100644 blob ");
	if (!line)
		return TRUE;
 * Blame backend
 *
 * Loading the blame view is a two phase job:
 *
 *  1. File content is read either using opt_file from the
 *     filesystem or using git-cat-file.
 *  2. Then blame information is incrementally added by
 *     reading output from git-blame.
struct blame_commit {
	char id[SIZEOF_REV];		/* SHA1 ID. */
	char title[128];		/* First line of the commit message. */
	char author[75];		/* Author of the commit. */
	struct tm time;			/* Date from the author ident. */
	char filename[128];		/* Name of file. */
struct blame {
	struct blame_commit *commit;
	unsigned int header:1;
	char text[1];
};
#define BLAME_CAT_FILE_CMD "git cat-file blob %s:%s"
#define BLAME_INCREMENTAL_CMD "git blame --incremental %s %s"

static bool
blame_open(struct view *view)
{
	char path[SIZEOF_STR];
	char ref[SIZEOF_STR] = "";

	if (sq_quote(path, 0, opt_file) >= sizeof(path))
		return FALSE;

	if (*opt_ref && sq_quote(ref, 0, opt_ref) >= sizeof(ref))
		return FALSE;

	if (*opt_ref) {
		if (!string_format(view->cmd, BLAME_CAT_FILE_CMD, ref, path))
			return FALSE;
	} else {
		view->pipe = fopen(opt_file, "r");
		if (!view->pipe &&
		    !string_format(view->cmd, BLAME_CAT_FILE_CMD, "HEAD", path))
			return FALSE;
	}

	if (!view->pipe)
		view->pipe = popen(view->cmd, "r");
	if (!view->pipe)
		return FALSE;

	if (!string_format(view->cmd, BLAME_INCREMENTAL_CMD, ref, path))
		return FALSE;

	string_format(view->ref, "%s ...", opt_file);
	string_copy_rev(view->vid, opt_file);
	set_nonblocking_input(TRUE);

	if (view->line) {
		int i;

		for (i = 0; i < view->lines; i++)
			free(view->line[i].data);
		free(view->line);
	}

	view->lines = view->line_alloc = view->line_size = view->lineno = 0;
	view->offset = view->lines  = view->lineno = 0;
	view->line = NULL;
	view->start_time = time(NULL);

	return TRUE;
}

static struct blame_commit *
get_blame_commit(struct view *view, const char *id)
{
	size_t i;

	for (i = 0; i < view->lines; i++) {
		struct blame *blame = view->line[i].data;

		if (!blame->commit)
			continue;

		if (!strncmp(blame->commit->id, id, SIZEOF_REV - 1))
			return blame->commit;
	}

	{
		struct blame_commit *commit = calloc(1, sizeof(*commit));

		if (commit)
			string_ncopy(commit->id, id, SIZEOF_REV);
		return commit;
	}
}

static bool
parse_number(char **posref, size_t *number, size_t min, size_t max)
{
	char *pos = *posref;

	*posref = NULL;
	pos = strchr(pos + 1, ' ');
	if (!pos || !isdigit(pos[1]))
		return FALSE;
	*number = atoi(pos + 1);
	if (*number < min || *number > max)
		return FALSE;

	*posref = pos;
	return TRUE;
}

static struct blame_commit *
parse_blame_commit(struct view *view, char *text, int *blamed)
{
	struct blame_commit *commit;
	struct blame *blame;
	char *pos = text + SIZEOF_REV - 1;
	size_t lineno;
	size_t group;

	if (strlen(text) <= SIZEOF_REV || *pos != ' ')
		return NULL;

	if (!parse_number(&pos, &lineno, 1, view->lines) ||
	    !parse_number(&pos, &group, 1, view->lines - lineno + 1))
		return NULL;

	commit = get_blame_commit(view, text);
	if (!commit)
		return NULL;

	*blamed += group;
	while (group--) {
		struct line *line = &view->line[lineno + group - 1];

		blame = line->data;
		blame->commit = commit;
		blame->header = !group;
		line->dirty = 1;
	}

	return commit;
}

static bool
blame_read_file(struct view *view, char *line)
{
	if (!line) {
		FILE *pipe = NULL;

		if (view->lines > 0)
			pipe = popen(view->cmd, "r");
		else if (!view->parent)
			die("No blame exist for %s", view->vid);
		view->cmd[0] = 0;
		if (!pipe) {
			report("Failed to load blame data");
			return TRUE;
		}

		fclose(view->pipe);
		view->pipe = pipe;
		return FALSE;

	} else {
		size_t linelen = strlen(line);
		struct blame *blame = malloc(sizeof(*blame) + linelen);

		if (!line)
			return FALSE;

		blame->commit = NULL;
		strncpy(blame->text, line, linelen);
		blame->text[linelen] = 0;
		return add_line_data(view, blame, LINE_BLAME_ID) != NULL;
	}
}

static bool
match_blame_header(const char *name, char **line)
{
	size_t namelen = strlen(name);
	bool matched = !strncmp(name, *line, namelen);

	if (matched)
		*line += namelen;

	return matched;
}

static bool
blame_read(struct view *view, char *line)
{
	static struct blame_commit *commit = NULL;
	static int blamed = 0;
	static time_t author_time;

	if (*view->cmd)
		return blame_read_file(view, line);

	if (!line) {
		/* Reset all! */
		commit = NULL;
		blamed = 0;
		string_format(view->ref, "%s", view->vid);
		if (view_is_displayed(view)) {
			update_view_title(view);
			redraw_view_from(view, 0);
		}
		return TRUE;
	}

	if (!commit) {
		commit = parse_blame_commit(view, line, &blamed);
		string_format(view->ref, "%s %2d%%", view->vid,
			      blamed * 100 / view->lines);

	} else if (match_blame_header("author ", &line)) {
		string_ncopy(commit->author, line, strlen(line));

	} else if (match_blame_header("author-time ", &line)) {
		author_time = (time_t) atol(line);

	} else if (match_blame_header("author-tz ", &line)) {
		long tz;

		tz  = ('0' - line[1]) * 60 * 60 * 10;
		tz += ('0' - line[2]) * 60 * 60;
		tz += ('0' - line[3]) * 60;
		tz += ('0' - line[4]) * 60;

		if (line[0] == '-')
			tz = -tz;

		author_time -= tz;
		gmtime_r(&author_time, &commit->time);

	} else if (match_blame_header("summary ", &line)) {
		string_ncopy(commit->title, line, strlen(line));

	} else if (match_blame_header("filename ", &line)) {
		string_ncopy(commit->filename, line, strlen(line));
		commit = NULL;
	}

	return TRUE;
}

static bool
blame_draw(struct view *view, struct line *line, unsigned int lineno, bool selected)
{
	struct blame *blame = line->data;
	int col = 0;

	if (opt_date) {
		struct tm *time = blame->commit && *blame->commit->filename
				? &blame->commit->time : NULL;

		col += draw_date(view, time, view->width, selected);
		if (col >= view->width)
			return TRUE;
	}

	if (opt_author) {
		int max = MIN(AUTHOR_COLS - 1, view->width - col);

		if (!selected)
			wattrset(view->win, get_line_attr(LINE_MAIN_AUTHOR));
		if (blame->commit)
			draw_text(view, blame->commit->author, max, TRUE, selected);
		col += AUTHOR_COLS;
		if (col >= view->width)
			return TRUE;
		wmove(view->win, lineno, col);
	}

	{
		int max = MIN(ID_COLS - 1, view->width - col);

		if (!selected)
			wattrset(view->win, get_line_attr(LINE_BLAME_ID));
		if (blame->commit)
			draw_text(view, blame->commit->id, max, FALSE, -1);
		col += ID_COLS;
		if (col >= view->width)
			return TRUE;
		wmove(view->win, lineno, col);
	}

	col += draw_lineno(view, lineno, view->width - col, selected);
	if (col >= view->width)
		return TRUE;

	col += draw_text(view, blame->text, view->width - col, TRUE, selected);
	return TRUE;
}

static enum request
blame_request(struct view *view, enum request request, struct line *line)
{
	enum open_flags flags = display[0] == view ? OPEN_SPLIT : OPEN_DEFAULT;
	struct blame *blame = line->data;

	switch (request) {
	case REQ_ENTER:
		if (!blame->commit) {
			report("No commit loaded yet");
			break;
		}

		if (!strcmp(blame->commit->id, NULL_ID)) {
			char path[SIZEOF_STR];

			if (sq_quote(path, 0, view->vid) >= sizeof(path))
				break;
			string_format(opt_cmd, "git diff-index --root --patch-with-stat -C -M --cached HEAD -- %s 2>/dev/null", path);
		}

		open_view(view, REQ_VIEW_DIFF, flags);
		break;

	default:
		return request;
	}

	return REQ_NONE;
}

static bool
blame_grep(struct view *view, struct line *line)
{
	struct blame *blame = line->data;
	struct blame_commit *commit = blame->commit;
	regmatch_t pmatch;

#define MATCH(text) \
	(*text && regexec(view->regex, text, 1, &pmatch, 0) != REG_NOMATCH)

	if (commit) {
		char buf[DATE_COLS + 1];

		if (MATCH(commit->title) ||
		    MATCH(commit->author) ||
		    MATCH(commit->id))
			return TRUE;

		if (strftime(buf, sizeof(buf), DATE_FORMAT, &commit->time) &&
		    MATCH(buf))
			return TRUE;
	}

	return MATCH(blame->text);

#undef MATCH
}

static void
blame_select(struct view *view, struct line *line)
{
	struct blame *blame = line->data;
	struct blame_commit *commit = blame->commit;

	if (!commit)
		return;

	if (!strcmp(commit->id, NULL_ID))
		string_ncopy(ref_commit, "HEAD", 4);
	else
		string_copy_rev(ref_commit, commit->id);
}

static struct view_ops blame_ops = {
	"line",
	blame_open,
	blame_read,
	blame_draw,
	blame_request,
	blame_grep,
	blame_select,
};

/*
 * Status backend
 */

struct status {
	char status;
	struct {
		mode_t mode;
		char rev[SIZEOF_REV];
		char name[SIZEOF_STR];
	} old;
	struct {
		mode_t mode;
		char rev[SIZEOF_REV];
		char name[SIZEOF_STR];
	} new;
};

static char status_onbranch[SIZEOF_STR];
static struct status stage_status;
static enum line_type stage_line_type;

/* Get fields from the diff line:
status_run(struct view *view, const char cmd[], char status, enum line_type type)
			if (status) {
				file->status = status;
				if (status == 'A')
					string_copy(file->old.rev, NULL_ID);
#define STATUS_DIFF_FILES_CMD "git diff-files -z"
#define STATUS_LIST_NO_HEAD_CMD \
	"git ls-files -z --cached --exclude-per-directory=.gitignore"
#define STATUS_DIFF_NO_HEAD_SHOW_CMD \
	"git diff --no-color --patch-with-stat /dev/null %s 2>/dev/null"

	char indexcmd[SIZEOF_STR] = STATUS_DIFF_INDEX_CMD;
	char othercmd[SIZEOF_STR] = STATUS_LIST_OTHER_CMD;
	char indexstatus = 0;
	view->lines = view->line_alloc = view->line_size = view->lineno = 0;
	if (!realloc_lines(view, view->line_size + 7))
	add_line_data(view, NULL, LINE_STAT_HEAD);
	if (opt_no_head)
		string_copy(status_onbranch, "Initial commit");
	else if (!*opt_head)
		string_copy(status_onbranch, "Not currently on any branch");
	else if (!string_format(status_onbranch, "On branch %s", opt_head))
	if (opt_no_head) {
		string_copy(indexcmd, STATUS_LIST_NO_HEAD_CMD);
		indexstatus = 'A';
	}

	if (!string_format(exclude, "%s/info/exclude", opt_git_dir))
		return FALSE;
		size_t cmdsize = strlen(othercmd);
		if (!string_format_from(othercmd, &cmdsize, " %s", "--exclude-from=") ||
		    sq_quote(othercmd, cmdsize, exclude) >= sizeof(othercmd))
			return FALSE;

		cmdsize = strlen(indexcmd);
		if (opt_no_head &&
		    (!string_format_from(indexcmd, &cmdsize, " %s", "--exclude-from=") ||
		     sq_quote(indexcmd, cmdsize, exclude) >= sizeof(indexcmd)))
	system("git update-index -q --refresh >/dev/null 2>/dev/null");

	if (!status_run(view, indexcmd, indexstatus, LINE_STAT_STAGED) ||
	    !status_run(view, STATUS_DIFF_FILES_CMD, 0, LINE_STAT_UNSTAGED) ||
	    !status_run(view, othercmd, '?', LINE_STAT_UNTRACKED))
	 * the context or select a line with something that can be
	 * updated. */
	if (prev_lineno >= view->lines)
		prev_lineno = view->lines - 1;
	while (prev_lineno < view->lines && !view->line[prev_lineno].data)
		prev_lineno++;
	while (prev_lineno > 0 && !view->line[prev_lineno].data)
		prev_lineno--;

	/* If the above fails, always skip the "On branch" line. */
		view->lineno = 1;

	if (view->lineno < view->offset)
		view->offset = view->lineno;
	else if (view->offset + view->height <= view->lineno)
		view->offset = view->lineno - view->height + 1;
	char *text;
	int col = 0;
		/* No attributes. */

	} else if (line->type == LINE_STAT_HEAD) {
		wattrset(view->win, get_line_attr(LINE_STAT_HEAD));
		wchgat(view->win, -1, 0, LINE_STAT_HEAD, NULL);
		case LINE_STAT_HEAD:
			text = status_onbranch;
			break;

	} else {
		char buf[] = { status->status, ' ', ' ', ' ', 0 };
		col += draw_text(view, buf, view->width, TRUE, selected);
		if (!selected)
			wattrset(view->win, A_NORMAL);
		text = status->new.name;
	draw_text(view, text, view->width - col, TRUE, selected);
	enum open_flags split;
		if (opt_no_head) {
			if (!string_format_from(opt_cmd, &cmdsize,
						STATUS_DIFF_NO_HEAD_SHOW_CMD,
						newpath))
				return REQ_QUIT;
		} else {
			if (!string_format_from(opt_cmd, &cmdsize,
						STATUS_DIFF_INDEX_SHOW_CMD,
						oldpath, newpath))
				return REQ_QUIT;
		}

	case LINE_STAT_HEAD:
		return REQ_NONE;

	split = view_is_displayed(view) ? OPEN_SPLIT : 0;
	open_view(view, REQ_VIEW_STAGE, OPEN_RELOAD | split);
status_exists(struct status *status, enum line_type type)
{
	struct view *view = VIEW(REQ_VIEW_STATUS);
	struct line *line;

	for (line = view->line; line < view->line + view->lines; line++) {
		struct status *pos = line->data;

		if (line->type == type && pos &&
		    !strcmp(status->new.name, pos->new.name))
			return TRUE;
	}

	return FALSE;
}


static FILE *
status_update_prepare(enum line_type type)
		return NULL;

	switch (type) {
	case LINE_STAT_STAGED:
		string_add(cmd, cmdsize, "git update-index -z --index-info");
		break;

	case LINE_STAT_UNSTAGED:
	case LINE_STAT_UNTRACKED:
		string_add(cmd, cmdsize, "git update-index -z --add --remove --stdin");
		break;

	default:
		die("line type %d not handled in switch", type);
	}

	return popen(cmd, "w");
}

static bool
status_update_write(FILE *pipe, struct status *status, enum line_type type)
{
	char buf[SIZEOF_STR];
	size_t bufsize = 0;
	size_t written = 0;
					status->old.mode,
	return written == bufsize;
}

static bool
status_update_file(struct status *status, enum line_type type)
{
	FILE *pipe = status_update_prepare(type);
	bool result;

	if (!pipe)
		return FALSE;

	result = status_update_write(pipe, status, type);
	return result;
}
static bool
status_update_files(struct view *view, struct line *line)
{
	FILE *pipe = status_update_prepare(line->type);
	bool result = TRUE;
	struct line *pos = view->line + view->lines;
	int files = 0;
	int file, done;

	if (!pipe)
	for (pos = line; pos < view->line + view->lines && pos->data; pos++)
		files++;

	for (file = 0, done = 0; result && file < files; line++, file++) {
		int almost_done = file * 100 / files;

		if (almost_done > done) {
			done = almost_done;
			string_format(view->ref, "updating file %u of %u (%d%% done)",
				      file, files, done);
			update_view_title(view);
		}
		result = status_update_write(pipe, line->data, line->type);
	}

	pclose(pipe);
	return result;
static bool
		/* This should work even for the "On branch" line. */
		if (line < view->line + view->lines && !line[1].data) {
			report("Nothing to update");
			return FALSE;
		if (!status_update_files(view, line + 1)) {
			report("Failed to update file status");
			return FALSE;
	} else if (!status_update_file(line->data, line->type)) {
		return FALSE;

	return TRUE;
		if (!status_update(view))
			return REQ_NONE;
	case REQ_VIEW_BLAME:
		if (status) {
			string_copy(opt_file, status->new.name);
			opt_ref[0] = 0;
		}
		return request;

	case LINE_STAT_HEAD:
static bool
stage_diff_write(FILE *pipe, struct line *line, struct line *end)
	while (line < end) {
		if (!stage_diff_line(pipe, line++))
			return FALSE;
		if (line->type == LINE_DIFF_CHUNK ||
		    line->type == LINE_DIFF_HEADER)
			break;
	}
	return TRUE;
}
static struct line *
stage_diff_find(struct view *view, struct line *line, enum line_type type)
{
	for (; view->line < line; line--)
		if (line->type == type)
			return line;
stage_update_chunk(struct view *view, struct line *chunk)
	struct line *diff_hdr;
	diff_hdr = stage_diff_find(view, chunk, LINE_DIFF_HEADER);
				"git apply --whitespace=nowarn --cached %s - && "
	if (!stage_diff_write(pipe, diff_hdr, chunk) ||
	    !stage_diff_write(pipe, chunk, view->line + view->lines))
		chunk = NULL;
	return chunk ? TRUE : FALSE;
static bool
	struct line *chunk = NULL;

	if (!opt_no_head && stage_line_type != LINE_STAT_UNTRACKED)
		chunk = stage_diff_find(view, line, LINE_DIFF_CHUNK);

	if (chunk) {
		if (!stage_update_chunk(view, chunk)) {
			return FALSE;
		}

	} else if (!stage_status.status) {
		view = VIEW(REQ_VIEW_STATUS);

		for (line = view->line; line < view->line + view->lines; line++)
			if (line->type == stage_line_type)
				break;

		if (!status_update_files(view, line + 1)) {
			report("Failed to update files");
			return FALSE;
	} else if (!status_update_file(&stage_status, stage_line_type)) {
		return FALSE;
	return TRUE;
		if (!stage_update(view, line))
			return REQ_NONE;
	case REQ_REFRESH:
		/* Reload everything ... */
	case REQ_VIEW_BLAME:
		if (stage_status.new.name[0]) {
			string_copy(opt_file, stage_status.new.name);
			opt_ref[0] = 0;
		}
		return request;

	case REQ_ENTER:
		return pager_request(view, request, line);

	open_view(view, REQ_VIEW_STATUS, OPEN_RELOAD | OPEN_NOMAXIMIZE);

	/* Check whether the staged entry still exists, and close the
	 * stage view if it doesn't. */
	if (!status_exists(&stage_status, stage_line_type))
		return REQ_VIEW_CLOSE;

	if (stage_line_type == LINE_STAT_UNTRACKED)
		opt_pipe = fopen(stage_status.new.name, "r");
	else
		string_copy(opt_cmd, view->cmd);
	open_view(view, REQ_VIEW_STAGE, OPEN_RELOAD | OPEN_NOMAXIMIZE);

	bool has_parents;		/* Rewritten --parents seen. */
	if (opt_date) {
		col += draw_date(view, &commit->time, view->width, selected);
		if (col >= view->width)
			return TRUE;
	}
	if (opt_author) {
		int max_len;
		max_len = view->width - col;
		if (max_len > AUTHOR_COLS - 1)
			max_len = AUTHOR_COLS - 1;
		draw_text(view, commit->author, max_len, TRUE, selected);
		col += AUTHOR_COLS;
		if (col >= view->width)
			return TRUE;
		size_t graph_size = view->width - col;
		if (graph_size > commit->graph_size)
			graph_size = commit->graph_size;
		for (i = 0; i < graph_size; i++)
		if (col >= view->width)
			return TRUE;
		waddch(view->win, ' ');
	if (opt_show_refs && commit->refs) {
			else if (commit->refs[i]->head)
				wattrset(view->win, get_line_attr(LINE_MAIN_HEAD));
			else if (commit->refs[i]->ltag)
				wattrset(view->win, get_line_attr(LINE_MAIN_LOCAL_TAG));
			else if (commit->refs[i]->tracked)
				wattrset(view->win, get_line_attr(LINE_MAIN_TRACKED));

			col += draw_text(view, "[", view->width - col, TRUE, selected);
			col += draw_text(view, commit->refs[i]->name, view->width - col,
					 TRUE, selected);
			col += draw_text(view, "]", view->width - col, TRUE, selected);
			col += draw_text(view, " ", view->width - col, TRUE, selected);
			if (col >= view->width)
				return TRUE;
	draw_text(view, commit->title, view->width - col, TRUE, selected);
		if (!view->lines && !view->parent)
			die("No revisions match the given arguments.");

		while ((line = strchr(line, ' '))) {
			line++;
			push_rev_graph(graph->parents, line);
			commit->has_parents = TRUE;
		}
		if (commit->has_parents)
			break;
	if (c == '\t')
		return opt_tab_size;

 * shown. If the reserve flag is TRUE, it will reserve at least one
 * trailing character, which can be useful when drawing a delimiter.
utf8_length(const char *string, size_t max_width, int *trimmed, bool reserve)
	unsigned char last_bytes = 0;
			if (reserve && width - ucwidth == max_width) {
				string -= last_bytes;
			}
		last_bytes = bytes;
static struct ref *refs = NULL;
static size_t refs_alloc = 0;
static size_t refs_size = 0;
static struct ref ***id_refs = NULL;
static size_t id_refs_alloc = 0;
static size_t id_refs_size = 0;
	size_t ref_list_alloc = 0;
	tmp_id_refs = realloc_items(id_refs, &id_refs_alloc, id_refs_size + 1,
				    sizeof(*id_refs));
		tmp = realloc_items(ref_list, &ref_list_alloc,
				    ref_list_size + 1, sizeof(*ref_list));
	bool ltag = FALSE;
	bool tracked = FALSE;
	bool check_replace = FALSE;
	bool head = FALSE;
		if (!strcmp(name + namelen - 3, "^{}")) {
			namelen -= 3;
			name[namelen] = 0;
			if (refs_size > 0 && refs[refs_size - 1].ltag == TRUE)
				check_replace = TRUE;
		} else {
			ltag = TRUE;
		}
		tracked  = !strcmp(opt_remote, name);
		head	 = !strncmp(opt_head, name, namelen);
		opt_no_head = FALSE;
	if (check_replace && !strcmp(name, refs[refs_size - 1].name)) {
		/* it's an annotated tag, replace the previous sha1 with the
		 * resolved commit id; relies on the fact git-ls-remote lists
		 * the commit id of an annotated tag right beofre the commit id
		 * it points to. */
		refs[refs_size - 1].ltag = ltag;
		string_copy_rev(refs[refs_size - 1].id, id);

		return OK;
	}
	refs = realloc_items(refs, &refs_alloc, refs_size + 1, sizeof(*refs));
	ref->head = head;
	ref->ltag = ltag;
	ref->tracked = tracked;
	/* branch.<head>.remote */
	if (*opt_head &&
	    !strncmp(name, "branch.", 7) &&
	    !strncmp(name + 7, opt_head, strlen(opt_head)) &&
	    !strcmp(name + 7 + strlen(opt_head), ".remote"))
		string_ncopy(opt_remote, value, valuelen);

	if (*opt_head && *opt_remote &&
	    !strncmp(name, "branch.", 7) &&
	    !strncmp(name + 7, opt_head, strlen(opt_head)) &&
	    !strcmp(name + 7 + strlen(opt_head), ".merge")) {
		size_t from = strlen(opt_remote);

		if (!strncmp(value, "refs/heads/", STRING_SIZE("refs/heads/"))) {
			value += STRING_SIZE("refs/heads/");
			valuelen -= STRING_SIZE("refs/heads/");
		}

		if (!string_format_from(opt_remote, &from, "/%s", value))
			opt_remote[0] = 0;
	}

load_git_config(void)
	} else if (opt_cdup[0] == ' ') {
	} else {
		if (!strncmp(name, "refs/heads/", STRING_SIZE("refs/heads/"))) {
			namelen -= STRING_SIZE("refs/heads/");
			name	+= STRING_SIZE("refs/heads/");
			string_ncopy(opt_head, name, namelen);
		}
	int result;
	FILE *pipe = popen("(git rev-parse --git-dir --is-inside-work-tree "
			   " --show-cdup; git symbolic-ref HEAD) 2>/dev/null", "r");

	/* XXX: The line outputted by "--show-cdup" can be empty so
	 * initialize it to something invalid to make it possible to
	 * detect whether it has been set or not. */
	opt_cdup[0] = ' ';

	result = read_properties(pipe, "=", read_repo_info);
	if (opt_cdup[0] == ' ')
		opt_cdup[0] = 0;

	return result;
	if (load_git_config() == ERR)
	if (!opt_git_dir[0] && opt_request != REQ_VIEW_PAGER)
	if (*opt_encoding && strcasecmp(opt_encoding, "UTF-8"))
		opt_utf8 = FALSE;

	if (*opt_git_dir && load_refs() == ERR)