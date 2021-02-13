-- article
INSERT INTO article(id,title,body,created_at,updated_at) VALUES (1,'Hello World', "", "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO article(id,title,body,created_at,updated_at) VALUES (2,'Hello World', "", "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO article(id,title,body,created_at,updated_at) VALUES (3,'Hello World', "", "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO article(id,title,body,created_at,updated_at) VALUES (4,'Hello World', "", "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO article(id,title,body,created_at,updated_at) VALUES (5,'Hello World', "", "2020-12-01 00:00:00", "2020-12-01 00:00:00");

-- tag
INSERT INTO tag(id,name,created_at,updated_at) VALUES (1,'treefrog', "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO tag(id,name,created_at,updated_at) VALUES (2,'ship', "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO tag(id,name,created_at,updated_at) VALUES (3,'computer science', "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO tag(id,name,created_at,updated_at) VALUES (4,'shrine', "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO tag(id,name,created_at,updated_at) VALUES (5,'dinner', "2020-12-01 00:00:00", "2020-12-01 00:00:00");
INSERT INTO tag(id,name,created_at,updated_at) VALUES (6,'dog', "2020-12-01 00:00:00", "2020-12-01 00:00:00");

-- user
INSERT INTO user(username,password,created_at,updated_at) VALUES ('admin','adminpass', "2020-12-01 00:00:00", "2020-12-01 00:00:00");


-- article_tag
INSERT INTO article_tag(id,article_id,tag_id) VALUES (1,1,1);
INSERT INTO article_tag(id,article_id,tag_id) VALUES (2,1,3);
