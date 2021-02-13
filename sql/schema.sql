
CREATE TABLE user (
    username VARCHAR(128) PRIMARY KEY
    ,password VARCHAR(128)
    -- yyyy-mm-dd hh:mm:ss
    ,created_at VARCHAR(19) 
    -- yyyy-mm-dd hh:mm:ss
    ,updated_at VARCHAR(19) 
    ,lock_revision INTEGER
);

CREATE TABLE article(
    id INTEGER AUTO_INCREMENT PRIMARY KEY
    ,title VARCHAR(20)
    ,body VARCHAR(200)
    -- yyyy-mm-dd hh:mm:ss
    ,created_at VARCHAR(19) 
    -- yyyy-mm-dd hh:mm:ss
    ,updated_at VARCHAR(19) 
    ,lock_revision INTEGER
)
;

CREATE TABLE tag(
    id INTEGER AUTO_INCREMENT PRIMARY KEY
    ,name VARCHAR(20)
    -- yyyy-mm-dd hh:mm:ss
    ,created_at VARCHAR(19) 
    -- yyyy-mm-dd hh:mm:ss
    ,updated_at VARCHAR(19) 
    ,lock_revision INTEGER
);

CREATE TABLE article_tag(
    id INTEGER AUTO_INCREMENT PRIMARY KEY
    ,article_id INTEGER
    ,tag_id INTEGER
    ,unique(article_id, tag_id)
)
;