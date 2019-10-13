* check installation

command: `docker version`

​	verify cli can talk to engine

command: `docker info`

​	most config values of engine

docker command line structure

​	old (still works): `docker <command> (options)`

​	new: `docker <command> <sub-command> (options)`

* Start a Nginx web server

  * container is an instance of an image
  * `docker container run --publish 80:80 nginx`
    1. Download image 'nginx' from docker hub
    2. Started a new container from that image
    3. Opened port 80 on the host IP
    4. Routes that traffic to the container IP, port 80
  * `docker container run --publish 80:80 --detach nginx` or `docker container run -p 80:80 -d nginx`
  * `docker container ls` (shows only running containers) or `docker contaienr ls -a` (shows all containers)
  * `docker container logs [container-name/id]`
  * `docker container top [container]`: show process running in container
  * `docker container rm [-f] [container-name/id]`

* What happends in `docker container run`

  1. looks for that image locally in image cache, doesn't find anything
  2. then looks in remote image repository (defaults to docker hub)
  3. downloads the latest version (nginx:latest by default)
  4. creates new container based on that image and prepares to start
  5. gives it a virtual IP on a private network inside docker engine
  6. opens up port 80 on host and forwards to port 80 in container
  7. starts container by using the cmd in the image dockerfile

  * Changing the defaults

    `docker container run --publish 8080:80 --name webhost -d nginx:1.11 nginx -T`

    * changed host listening port
    * changed version of image
    * changed cmd run on start

* What's Going On In Containers

  * `docker container top` -- process list in one container
  * `docker container inspect` -- details of one container config
  * `docker container stats` -- performance stats for all containers

* Getting a Shell Inside Containers

  * `docker container run -it` -- start new container interactively
  * `docker container exec -it` -- run additional command in existing container
  * `docker container start -ai ubuntu` -- use `ai` option

* Docker Networks: Concepts

  * network: `bridge` -- default network
  * network: `host` -- directly attached to host network
  * network: `none` -- not attached to any network
  * `docker container port <container>`
  * `docker container inspect --format "{{.NetworkSettings.IPAddress}} <container>"` 

* Docker Networks: CLI Management
  * `docker network ls` -- show networks
  * `docker network inspect` -- Inspect a network
  * `docker network create --driver` -- create a network
  * `docker network connect <net> <container>` -- attach a network to container
  * `docker network disconnect` -- detach a network from container
  * `docker container run --network <net> --name nginx -d nginx`
  
* Docker Networks: DNS
  * use `--link` to enable DNS on default bridge network (create net network would be easier)
  * containers shouldn't rely on IP's for inter-communication
  * DNS for friendly names is built-in if you use custom networks
  
* DNS Round Robin Test
  * use `--network-alias <alias>` 
  * `docker container run --rm --net dude --net-alias search elasticsearch:2`, run this two times
  * `docker container exec -it ubuntu curl search:9200`
  
* What's In An Image (And What Is Image)
  * App binaries and dependencies
  * Metadata about the image data and how to run the image
  * Not a complete OS. No kernel, kernel modules (e.g. drivers)
  * Small as one file (your app binary) like a golang static binary
  * Big as a Ubuntu distro with apt, and Apache, PHP, and more installed

* Docker Image
  * `docker  image history [image]`
  * images are made up of file system changes and metadata
  * each layer is uniquely identified and only stored once on a host
  * this saves storage space on host and transfer time on push/pull
  * A container is just a single read/write layer on top of image
  * container copies on write
  * `docker image inspect [nginx]`
  
* Image Tagging and Pushing to Docker Hub
  * `docker login <server>` `docker logout` -- login to server, the default is docker hub
  * `echo [base64-encoded] | base64 -d`
  * `docker image push skybro/nginx`
  * if you want to create a private docker hub image, you should create the repository first before you upload it
  
* Building Images

  * `docker image build -t customnginx .`
  * [Best practices for writing Dockerfiles](https://docs.docker.com/develop/develop-images/dockerfile_best-practices/)

* Container lifetime & Persistent Data

  * Data Volumes
    * make special location outside of container UFS
    * attach to containers
    * need manual deletion
    * `docker volume prune`
    * `docker volume ls`
    * `docker volume inspect <volume>`
    * `docker container run -v mysql-db:/var/lib/mysql mysql`: a named volume
    * `docker  volume create [options] [volume]`
  * Bind Mounts
    * link container path to host path
    * `docker container run -v $(pwd):/usr/share/nginx/html nginx`: like volume, but with a `/` at front

* 48