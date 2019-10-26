import { Router } from "express";
import token from "./token";

export default (async (): Promise<Router> => {
    const router = Router();
    router.get("/token", token);
    return router;
})();