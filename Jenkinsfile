pipeline {
    agent any
    stages 
    {
        stage('Build') 
        {
            steps 
            {
                script
                {
                    sh "ls -la"
                    sh "docker build -t cont_build ."
                }
            }
            post 
            {
                failure 
                {
                    // send email notification on failure
                    script
                    {
                        sh "docker container prune | 'y'"
                        sh "docker volume prune | 'y'"
                    }
                    emailext body: "The 'build' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "lordaleks2001WoW@gmail.com"
                }
            }
        }

        stage('Test') 
        {
            agent any
            steps 
            {
                script
                {
                    sh "docker build -t cont_test -f Dockerfile.second ."
                }
            }
            post 
            {
                failure 
                {
                    script
                    {
                        sh "docker container prune | 'y'"
                        sh "docker volume prune | 'y'"
                    }
                    // send email notification on failure
                    emailext body: "The 'test' stage has failed. Please check the build logs for more details.",
                        subject: "Pipeline failure",
                        to: "lordaleks2001WoW@gmail.com"
                }
            }
        }

        stage('Deploy') 
        {
            agent any
            steps 
            {
                script
                {
                    sh "docker build -t cont_deploy -f Dockerfile.third ."
                }
            }
        }

        stage('Publish') {
            agent any
            steps 
            {
                sh "docker save cont_deploy | gzip > docker-image.tar.gz"
                archiveArtifacts artifacts: 'docker-image.tar.gz', allowEmptyArchive: true
                sh "docker container prune"
                sh "docker volume prune"
                sh "docker image prune "
            }
        }
    }
}
