import Link from 'next/link'
import {useRouter} from 'next/router'

const article = ({article}) => {
    // const router = useRouter()
    // const {id} = router.query

    return (
        <>
            <h1>{article.title}</h1>
            <p>{article.body}</p>
            <br />
            <Link href='/'>Go Back</Link>
        </>
    )
}

export const getStaticProps = async (context) => {
    

    return {
        props: {
            article
        }
    }
}

export const getStaticPaths = async () => {
    const res = await fetch(`https://jsonplaceholder.typicode.com/posts`)

    const article = await res.json()
}

export default article
