import Configuration from "./Config";

const config = new Configuration();

export default config;

export const redis = config.clients.redis;
