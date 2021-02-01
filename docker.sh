set -eu
MYSQL_ROOT_PASSWORD=testpassword
DATABASE_NAME=db_example

container_id=`docker run --name mariadb -p 3306:3306 -e MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD} -d mariadb:latest`

echo "Alrady run mysql"
echo container_id=${container_id}

# create Database
# mysql -u root -p${MYSQL_ROOT_PASSWORD} -h 127.0.0.1 -e "CREATE DATABASE ${DATABASE_NAME};"

# login database.
# mysql  -u root -p${MYSQL_ROOT_PASSWORD} $DATABASE_NAME -h 127.0.0.1