/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zosobiro <zosobiro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 21:32:22 by ivaliev           #+#    #+#             */
/*   Updated: 2023/06/02 20:30:01 by zosobiro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdlib.h>
# include <stdio.h>
# include <signal.h>
# include <string.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <unistd.h>
# include <sys/wait.h>
# include <errno.h>
# include "libft/libft.h"
# include <fcntl.h>

# define WORD 1
# define S_QUOTE 2 // '
# define D_QUOTE 3 // "
# define N_LINE 4 // \n
# define W_SPACE 5 // whitespace
# define GREAT 6 // >
# define D_GREAT 7 // >>
# define LESS 8 // <
# define D_LESS 9 // <<
# define PIPE 10 // |
# define DOLLAR 11 // $
# define BACKSLASH 12 //

// extern struct s_vars *vars;

/*------------------env copy list-----------------*/
typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;
/*------------------env copy list-----------------*/

typedef struct s_token
{
	struct s_token	*prev;
	int				type;
	int				pos;
	char			*data;
	struct s_token	*next;
}	t_token;

typedef struct s_cmd
{
	struct s_cmd	*prev;
	int				fd[2];
	char			**args;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_cmds
{
	int		nb_cmd;
	t_cmd	*cmd;
}			t_cmds;
/*----------------------------------------*/
/*----------------------------------------*/
/*------------------------------*/
// create a linked list of cmd (only type WORD)
// create a linked list of input ( LESS, D_LESS)
// create a linked list of output ( GREAT, D_GREAT)
/*------------------------------*/
typedef struct s_comd
{
	struct s_comd	*prev;
	char			*data;
	struct s_comd	*next;
}				t_comd;

typedef struct s_allput
{
	struct s_allput	*prev;
	t_comd			*data;
	int				infile;
	int				outfile;
	struct s_allput	*next;
}				t_allput;
/*------------------------------*/

typedef struct s_cmd2
{
	struct s_cmd2	*prev;
	t_comd			*comd;
	t_allput		*input;
	t_allput		*output;
	int				fd[2];
	struct s_cmd2	*next;
}				t_cmd2;

typedef struct s_cmds2
{
	int		nb_cmd;
	t_cmd2	*cmd;
}			t_cmds2;
/*----------------------------------------*/
/*GLOBAL VAR---------------*/
typedef struct s_vars
{
	char	**env_clone;
	int		exit_status;
	int		fd_in;
	int		fd_out;
	int		flag;
	t_env	*copy_env;
	t_token	*token;
	t_cmds2	*cmds;
}				t_vars;
extern t_vars	*g_vars;
/*------------------------*/
/*--------------*/
void		ft_free_vars(void);
void		ft_free_vars2(void);
void		print_tab(char **data);
void		print_env(t_env *copy_env);

/*--------------*/
/*------------------LEXER-----------------*/
t_token		*ft_parser(char *cmd, char **env, int *err);
void		ft_syntax_err(t_token **tok, t_token **new, int **err);
t_token		*ft_lexer(char *cmd);
int			find_type(char *str);
int			ft_type(char c);
/*------------------LEXER-----------------*/
void		ft_destroy_comd(t_comd **comd);
void		ft_destroy_allput(t_allput **allput);
void		ft_destroy_cmd2(t_cmd2 **cmd);
void		ft_destroy_cmds2(t_cmds2 **cmds);

/*------------------TOKEN-----------------*/
t_token		*create_tok(int type, int pos, char *data);
void		last_token(t_token **token);
void		addback_token(t_token **token, int type, int pos, char *data);
void		ft_destroy_tokens(t_token **token);
void		change_pointer(t_token **token, t_token **new);
int			ft_token_len(t_token *token);
int			ft_no_quotes(t_token *token);
void		print_tokens(t_token *token); // remove me
void		print_tok(t_token *token); // remove me
/*------------------TOKEN-----------------*/

/*------------------QUOTES----------------*/
int			check_quotes(t_token *tokens);
t_token		*check_last_quote(t_token *token, int type, int *count);
int			check_last_token(t_token	*token);
/*------------------QUOTES----------------*/

/*------------------PIPES-----------------*/
int			valid_pipe_type(t_token *token);
int			valid_pipe(t_token **tmp);
int			nb_pipes(t_token *token);
/*------------------PIPES-----------------*/

/*------------------REDIRS-----------------*/
int			is_redir(int type);
int			valid_redir(t_token *token);
/*------------------REDIRS-----------------*/

/*---------------FT_CONVERT---------------*/
int			is_symbol(char c);
char		*ft_trans_str(char *str);
void		ft_convert(t_token **token, t_token **new_token);
void		ft_convert_dollar(t_token **token, t_token **tmp);
char		*ft_find_var(char *new_str);
void		find_var_part(char *new_str, char **str);
int			is_another_symb(char *str);
int			is_another_digit(char *str);
void		ft_convert_quote(t_token **token, t_token **tmp);
void		ft_dollar_str(t_token **token, char **str);
void		ft_quote_4(t_token **token, t_token **tmp_tok, char **str_tmp);
void		ft_add_2(t_token **tok, t_token **new);
void		ft_add_1(t_token **tok, t_token **new, t_token **tmp);
void		ft_quote3(t_token **tok, t_token **tmp);
void		ft_quote3_1(t_token **tok, t_token **tmp, char **str);
void		ft_quote2(t_token **tok, t_token **new, t_token **tmp, char **str);
void		ft_quote1(t_token **tok, t_token **tmp_tok, char **str_tmp);
void		ft_handle_quote1(t_token **token, t_token **tmp, int pos);
char		*str_quoted(t_token **token, int type);
void		join_all_str(t_token **tmp, char **str, int type);
void		ft_handle_quote1(t_token **token, t_token **tmp, int pos);
void		ft_double_free(t_token **tmp, char **str_tmp);
void		join_all_str(t_token **tmp, char **str, int type);
void		join_all_part(t_token **tmp, char **str, char **str_tmp);
char		*ft_dollar_helper(t_token **token);
int			ft_dummpy_token_check(t_token *token, char **str);
void		ft_quote_care(t_token **token,
				t_token **new_token, t_token **tmp_tok, char **str_tmp);
void		quote_core(t_token **token, t_token **tmp_tok, char **str_tmp2);
/*---------------FT_CONVERT---------------*/

char		*ft_make_new_line(t_token **token);
int			is_new_line(char *str);
int			is_valid_new_line(char *str);
int			valid_pos_nline(t_token *token);
int			empty_but_space(t_token *token);
/*---------------FT_MAKING CMDs---------------*/
t_cmds		*ft_make_cmds(t_token *token);
t_cmd		*ft_make_cmd(t_token *token);
/*---------------FT_MAKING CMDs---------------*/

/*-------------------FT_CMD-------------------*/
int			cmd_len(t_cmd *cmd);
char		*ft_make_str(char *str);
char		**ft_tab_args(t_token **token);
t_cmd		*create_cmd(t_token **token);
void		add_back_cmd(t_cmd **cmd, t_token **token);
void		to_last_cmd(t_cmd **cmd);
int			tab_len(t_token *token);
/*-------------------FT_CMD-------------------*/

void		print_cmd(t_cmd *cmd);
void		print_cmds(t_cmds *cmds);

/*-------------------FT_CMD2-------------------*/
void		add_back_cmd2(t_cmd2 **cmd, t_token **token);
t_cmd2		*create_cmd2(t_token **token);
void		to_last_cmd2(t_cmd2 **cmd);
/*-------------------FT_CMD2-------------------*/

/*-------------------FT_CMDs2-------------------*/
t_cmds2		*ft_make_cmds2(t_token *token);
t_cmd2		*ft_make_cmd2(t_token *token);
/*-------------------FT_CMDs2-------------------*/

/*-------------------FT_COMD-------------------*/
t_comd		*ft_make_comd(t_token **token);
void		add_back_comd(t_comd **comd, char *str);
t_comd		*create_comd(char *str);
void		to_last_comd(t_comd **comd);
void		ft_make_comd_part(t_token *tmp, t_comd **comd);
/*-------------------FT_COMD-------------------*/

/*-------------------FT_WORD-------------------*/
int			pos_of_symb(char *str);
void		ft_join_tok2(t_token **token, char **str);
void		ft_join_word2(t_token **token, t_token **new);
void		ft_join_part2(t_token **token, char **str);
t_token		*ft_word(t_token **token);
void		ft_join_part1(t_token **token, char **str);
void		ft_expand0(char **str);
void		ft_expand4(t_token **token, char **str);
void		ft_expand1(t_token **token, char **str);
void		ft_expand3(t_token **token, char **str);
void		ft_expand2(t_token **token, char **str);
void		ft_join_str2(char *string, char **str);
void		ft_expand11(t_token **token, char **str);
void		ft_join_str1(char **tmp2, char **tmp3, char **tmp1, char **str);
void		ft_join_part2(t_token **token, char **str);
/*-------------------FT_WORD-------------------*/

/*-------------------FT_ALLPUT-------------------*/
t_allput	*ft_make_input(t_token **token);
t_allput	*ft_make_output(t_token **token);
void		add_back_allput(t_allput **allput, t_token **token);
t_allput	*create_allput(t_token **token);
char		**ft_tab_put(t_token **token);
void		to_last_allput(t_allput **allput);
t_comd		*ft_make_put(t_token **token);
/*-------------------FT_ALLPUT-------------------*/
void		print_newcmd(t_cmds2 *cmd);
/*-------------------FT_HELPERS-------------------*/
char		**make_clone_env(t_env *copy_env);
int			copy_env_len(t_env *env);
/*-------------------FT_HELPERS-------------------*/

/*-------------------FT_BUILTINS-------------------*/
void		ft_builtin(t_cmd2 *cmd, t_env *copy_env);
void		ft_forked_builtin(t_cmd2 *cmd, t_env *copy_env, int nb_cmd);
void		ft_echo(t_comd *real_token, int out_fd);
void		ft_env(t_env *head, int flag, int out_fd);
void		ft_unset(t_env **head, t_comd *command);
void		ft_export(t_env **head, t_comd *command, int out_fd);
void		ft_exit(t_cmd2 *cmd, t_env *copy_env);
/*-------------------FT_expor_utils-------------------*/
char		*ft_get_value(char *str);
int			ft_check_plus_sign(char *str);
int			ft_mini_error_handling(char *command, int flag_plus_equal);
void		ft_check_plus(char *str_n, char *str_v,
				t_env **head, t_env **newnode);
int			ft_error_getting_value(t_comd **command);
int			ft_checking_proper_str_name(char *str_name, t_comd **command);
/*-------------------FT_expor_utils-------------------*/
void		ft_cd(t_env **head, t_comd *command);
void		ft_pwd(int out_fd);
/*-------------------FT_BUILTINS-------------------*/

/*-------------------FT_copy_env-------------------*/
void		ft_copy_env(t_env **head, char **env);
// void	print_env(t_env *copy_env); // to remove
void		ft_delete_from_list(t_env **head, char *name);
t_env		*ft_search_list(t_env **head, char *name);
t_env		*ft_create_node(char *name, char *value);
void		ft_add_to_list(t_env **head, t_env *newnode);
/*-------------------FT_copy_env-------------------*/

/*-------------------FT_copy_env-------------------*/
/*-------------------FT_copy_env-------------------*/

/*-------------------FT_execve_utils-------------------*/
void		ft_multiple_pipes(t_cmd2 *commands, t_env *copy_env, int nb_cmd);
void		ft_cmd_exec(t_cmd2 *commands, int nb_cmd);
void		ft_close_pipes(t_cmd2 *commands, int nb_cmd);
void		ft_open_pipes(t_cmd2 **commands);
char		*ft_get_path(char *str, t_env *copy_env);
void		ft_dup2(t_cmd2 *commands, int fd_in, int fd_out);
int			ft_open_outfile(t_allput *output);
void		ft_close_outfile(t_allput *output);
void		ft_close_infile(t_allput *input);
int			ft_open_infile(t_allput *input);
int			check_builtin_cmds(t_cmd2 *cmd);
/*-------------------FT_execve_utils-------------------*/

/*-------------------convert list to array-------------------*/
int			ft_listsize1(t_comd *lst);
int			ft_listsize2(t_env *lst);
char		**ft_get_2darray1(t_comd *cmd);
char		**ft_get_2darray2(t_env *env);
/*-------------------convert list to array-------------------*/

/*-------------------Error-------------------*/
void		ft_putstr_err(char *file, char *str);
/*-------------------Error-------------------*/

/*-------------------here_doc-------------------*/
void		ft_heredoc(char *stop_str, t_allput *input);
int			call_heredoc(int in_fd, t_allput *input);
void		reset_fd(void);
void		ft_expr(t_cmd2 *cmds);
/*-------------------here_doc-------------------*/

/*-------------------ft_Free-------------------*/
void		ft_free_copy_env(t_env *copy_env);
void		ft_free_array(char **array);
void		ft_delete_first_n(t_comd **head);
/*-------------------ft_Free-------------------*/

#endif
