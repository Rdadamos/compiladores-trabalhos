import ox
import click
import pprint

lexer = ox.make_lexer([
    ('OPEN_P', r'\('),
	('CLOSE_P', r'\)'),
	('OP', r'[-a-zA-Z]+'),
	('NUMBER', r'[0-9]+'),
	('ignore_COMMENT', r';[^\n]*'),
	('ignore_NEWLINE', r'\s+'),
])

tokens = ['OP', 'NUMBER', 'OPEN_P', 'CLOSE_P']

atom = lambda x: x
term = lambda x: (x,)
comp = lambda x, y: (x,) + y
pare = lambda x, y: '()'
expr = lambda x, y, z: y
parser = ox.make_parser([
	('expr : OPEN_P term CLOSE_P', expr),
    ('expr : OPEN_P CLOSE_P'     , pare),
	('term : atom term'          , comp),
	('term : atom'               , term),
    ('atom : expr'               , atom),
    ('atom : OP'                 , atom),
    ('atom : NUMBER'             , atom),
], tokens)

@click.command()
@click.argument('file', type=click.File('r'))

def tree(file):
	pprint.pprint(parser(lexer(file.read())))

tree()
