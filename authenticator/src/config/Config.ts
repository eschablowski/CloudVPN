import { RedisClient, ClientOpts as RedisOpts, createClient } from "redis";
import { parse } from "yaml";

interface Clients {
  redis: RedisClient;
}

function generateClients(config: Configuration): Clients {
  return {
    redis: createClient(config.redis)
  }
}

export default class Configuration {
  redis: RedisOpts;
  clients: Clients
  constructor(yaml?: string) {
    if(yaml)
      parse(yaml);
    this.redis = {
      url: "redis.authenticator.cloudvpn.com"
    };
    this.clients = generateClients(this);
  };
}
