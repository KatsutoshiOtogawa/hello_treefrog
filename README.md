
```shell
# Bedore you git commit,
make clean
git commit
```

```shell
# create tablese
sqlite3 db/dbfile < sql/schema.sql

# create data
sqlite3 db/dbfile < sql/data.sql
```