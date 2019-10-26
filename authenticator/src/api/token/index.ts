import {Request, Response} from "express";
import {generateToken} from "./generateToken"

export default async (req: Request, res: Response): Promise<void> => {
    res.send(await generateToken());
}
