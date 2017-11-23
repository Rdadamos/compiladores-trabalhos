import ox

lexer = ox.make_lexer([
    ('SPACE'  , r'\s+')
    ('COMMENT', r';.*'),
    ('NAME'   , r'[-a-zA-Z]+'),
    ('NUMBER' , r'\d+'),
    ('OPEN_P' , r'\('),
    ('OPEN_F' , r'\)'),
    ('NEWLINE', r'\n'),
    ('DEF'    , 'def'),
    ('DO'     , 'do'),
    ('LOOP'   , 'loop'),
    ('RIGHT'  , 'right'),
    ('LEFT'   , 'left'),
    ('INC'    , 'inc'),
    ('DEC'    , 'dec'),
    ('PRINT'  , 'print'),
    ('READ'   , 'read'),
    ('ADD'    , 'add'),
    ('SUB'    , 'sub'),
])


tokens = ['SPACE', 'COMMENT', 'NAME', 'NUMBER', 'OPEN_P', 'OPEN_F', 'NEWLINE', 'DEF', 'DO', 'LOOP', 'RIGHT', 'LEFT', 'INC', 'DEC', 'PRINT', 'READ', 'ADD', 'SUB']
